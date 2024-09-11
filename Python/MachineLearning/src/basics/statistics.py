"""
Statistics module provides basic statistics functions
"""
import logging
import sys
from collections.abc import Sequence


class Stats[T]:
    """Class to calculate basics of statistics"""

    def __init__(self, data: Sequence[T]) -> None:
        self._data = data

    def min(self) -> T:
        '''Calculates min of Sequence'''
        logging.debug("Running min")
        mn = sys.maxsize

        for d in self._data:
            if d < mn:
                mn = d
        return mn

    def max(self) -> T:
        '''Calculates max of Sequence'''
        mx = -sys.maxsize -1

        for d in self._data:
            if d > mx:
                mx = d
        return mx

    def mean(self) -> T:
        '''Calculates mean of Sequence'''
        return sum(self._data)/len(self._data)

    def mode(self) -> T:
        '''Calculates mode of Sequence'''
        mx = -sys.maxsize-1
        res = None
        map = dict()
        for i in self._data:
            if i in map:
                map[i] = map[i] + 1
            else:
                map[i] = 1

            if map[i] > mx:
                mx = map[i]
                res = i
        return res

    def median(self) -> T:
        '''Calculate median of Sequence'''
        self._data = sorted(self._data)
        size = len(self._data)
        if not self._data:
            return None
        if size == 1:
            return self._data[0]
        if (size % 2) == 0:
            return (self._data[size//2] + self._data[size//2 - 1])/2

        return self._data[size//2]


class Histogram:
    """
    Calculates Histogram of data
    """

    def __init__(self) -> None:
        """
        Initialise data
        """
        pass

    def calculate(self, data, bins=10) -> dict:
        """
        Calculate histogram
        """
        mn = min(data)
        mx = max(data)
        bins = [i + (mx - mn) / bins for i in range(bins)]
        histogram = [0] * (len(bins) - 1)  # Initialize histogram with zeros
        for value in data:
            for i in range(len(bins) - 1):
                if bins[i] <= value < bins[i + 1]:
                    histogram[i] += 1
                    break
        return histogram

    def plot(self, data, bins=10) -> None:
        start_time = time.perf_counter()
        min_data = np.min(a)
        max_data = np.max(a)
        dx = (max_data - min_data) / bins
        print(time.perf_counter() - start_time, 'to calc min/max')

        x = np.zeros(bins)
        y = np.zeros(bins + 1)
        print(time.perf_counter() - start_time, 'to create x, y')

        for i in range(bins):
            x[i] = i * dx + min_data
        print(time.perf_counter() - start_time, 'to calc bin borders')

        a_to_bins = ((a - min_data) / dx).astype(int)
        print(time.perf_counter() - start_time, 'to calc bins')
        for bin in a_to_bins:
            y[bin] += 1
        print(time.perf_counter() - start_time, 'to fill bins')

        y[bins - 2] += y[bins - 1]
        y = y[:bins]

        if density == True:
            inte = sum((x[1] - x[0]) * y)
            y /= inte

        print(time.perf_counter() - start_time, 'before draw')
        plt.bar(x, y, width=dx)
        print(time.perf_counter() - start_time, 'after draw')
        return np.column_stack((x, y))