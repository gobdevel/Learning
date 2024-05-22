import unittest
from basics.statistics import Histogram


class HistogramTest(unittest.TestCase):

    def setUp(self) -> None:
        super().setUp()
        self._histogram = Histogram()


    def test_sanity(self) -> None:
        self.assertEqual(11, self._histogram.calculate())



if __name__ == '__main__':
    unittest.main()
