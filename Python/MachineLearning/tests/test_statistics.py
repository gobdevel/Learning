"""
Test cases for statistics module
"""

import unittest
from logger_config.logger import setup_logging
from parameterized import parameterized
import numpy as np
from scipy import stats as sci_stats
from basics.statistics import Stats


class StatsTest(unittest.TestCase):
    '''Test Stats'''

    @parameterized.expand(
        [
            ([2], 2),
            ([2, 5, 1, 9], 1),
            ([-8, 1, 0, -22], -22),
        ]
    )
    def test_min(self, data, expected) -> None:
        '''Validate min function'''
        stats = Stats(data)
        self.assertEqual(stats.min(), expected)

    @parameterized.expand(
        [
            ([2], 2),
            ([2, 5, 1, 9], 9),
            ([-8, 1, 0, -22], 1),
        ]
    )
    def test_max(self, data, expected) -> None:
        '''Validate min function'''
        stats = Stats(data)
        self.assertEqual(stats.max(), expected)

    @parameterized.expand(
        [
            ([2], None),
            ([2, 5, 1, 9], None),
            ([-8, 1, 0, -22], None),
            ([-8, 1, 0, -22, 21], None),
        ]
    )
    def test_mean(self, data, _) -> None:
        '''Validate min function'''
        stats = Stats(data)
        self.assertEqual(stats.mean(), np.mean(data))

    @parameterized.expand(
        [
            ([2], None),
            ([2, 5, 1, 1, 1, 9, 9], None),
            ([-8, -8, 0, -22], None),
            ([-8, 1, 0, -22, -22, 0, 0], None),
        ]
    )
    def test_mode(self, data, _) -> None:
        '''Validate mode function'''
        stats = Stats(data)
        self.assertEqual(stats.mode(), sci_stats.mode(data)[0])

    @parameterized.expand(
        [
            ([2], None),
            ([1, 2, 3], None),
            ([1, 2, 3, 4], None),
            ([-8, 1, 0, -22, -22, 0, 0], None),
        ]
    )
    def test_median(self, data, _) -> None:
        '''Validate median function'''
        stats = Stats(data)
        self.assertEqual(stats.median(), np.median(data))

    def test_median_empty(self) -> None:
        '''Validate median function'''
        stats = Stats([])
        self.assertEqual(stats.median(), None)


if __name__ == "__main__":
    setup_logging()
    unittest.main()
