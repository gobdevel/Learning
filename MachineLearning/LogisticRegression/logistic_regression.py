#
# Description: This file contains the implementation of
# the Logistic Regression algorithm.
#  y = 1.0 / (1.0 + exp(-z))
#  where z = w0 + w1*x1 + w2*x2 + ... + wn*xn ( n = number of features)
#
# Loss function: Maximum Likelihood Estimation
#  L(w) = -1/N * sum( y_i*log(y_hat_i) + (1-y_i)*log(1-y_hat_i) )
#  where y_hat_i = 1.0 / (1.0 + exp(-z_i))
#
# To solve the issue of floating point underflow, we can use the following
# trick:
#    y = log(1.0 / (1.0 + exp(-z)))
#    and to multiply use addition in log domain.

import math
import numpy as np
import pandas as pd


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "x: " + str(self.x) + ", y: " + str(self.y)


def predict_probability(x, b0, b1):
    p = 1.0 / (1.0 + math.exp(-b0 - b1 * x))
    return p


def build_model(points):
    b0 = 0.01  # Logistic function dont like 0 so we start with a small value
    b1 = 0.01
    best_likelihood = -1000000

    epoch = 10000

    for i in range(epoch):
        # select b0 or b1 randomaly and adjust it randomly
        random_b = np.random.choice([0, 1])
        random_adjust = np.random.normal()

        if random_b == 0:
            b0 += random_adjust
        else:
            b1 += random_adjust

        # calculate the loss (log likelihood)
        true_estimates = sum(
            math.log(predict_probability(p.x, b0, b1)) for p in points if p.y == 1.0
        )
        false_estimate = sum(
            math.log(1 - predict_probability(p.x, b0, b1))
            for p in points
            if p.y == 0.0
        )
        total_likelihood = true_estimates + false_estimate

        # if likelihood is greater than previous likelihood, keep the changes
        if best_likelihood < total_likelihood:
            best_likelihood = total_likelihood
            print(best_likelihood)
        else:
            if random_b == 0:
                b0 -= random_adjust
            else:
                b1 -= random_adjust
    return b0, b1


def plot(points, b0, b1):
    import matplotlib.pyplot as plt

    x = [p.x for p in points]
    y = [p.y for p in points]
    plt.scatter(x, y)

    x = np.linspace(min(x), max(x), 100)
    y = [predict_probability(i, b0, b1) for i in x]
    plt.plot(x, y, color="red")
    plt.show()


if __name__ == "__main__":
    points = [
        Point(row.x, row.y) for index, row in pd.read_csv("sample.txt").iterrows()
    ]
    b0, b1 = build_model(points)
    print(f'y = 1.0 / (1.0 + exp(-({b0} + {b1}*x))')
    plot(points, b0, b1)
