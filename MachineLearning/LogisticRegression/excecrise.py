# Predict whether a color is dark or light based on its RGB values. The data is in color_sample.txt. The first three columns are the RGB values, and the fourth column is 1 if the color is dark, and 0 if the color is light. Use logistic regression to build a model that predicts whether a color is dark or light based on its RGB values. Plot the data and the model.
import pandas as pd
import matplotlib.pyplot as plt
import math
import numpy as np
from mpl_toolkits.mplot3d import Axes3D


class ColorSample:
    def __init__(self, red, green, blue, dark_or_light):
        self.red = (red / 255.0 * 0.99) + 0.01
        self.green = (green / 255.0 * 0.99) + 0.01
        self.blue = (blue / 255.0 * 0.99) + 0.01
        self.dark_or_light = dark_or_light

    def __str__(self):
        return (
            "red: "
            + str(self.red)
            + ", green: "
            + str(self.green)
            + ", blue: "
            + str(self.blue)
            + ", dark_or_light: "
            + str(self.dark_or_light)
        )


def predict_probability(c, b0, b1, b2, b3):
    x = round(-(b0 + (b1 * c.red) + (b2 * c.green) + (b3 * c.blue)), 4)
    p = 1.0 / (1.0 + math.exp(x))
    return p


def build_model(color_samples):
    b0 = 0.01
    b1 = 0.01
    b2 = 0.01
    b3 = 0.01
    best_likelihood = -1000000
    epoch = 80000

    for i in range(epoch):
        random_b = np.random.choice([0, 1, 2, 3])
        random_adjust = np.random.normal()

        if random_b == 0:
            b0 += random_adjust
        elif random_b == 1:
            b1 += random_adjust
        elif random_b == 2:
            b2 += random_adjust
        else:
            b3 += random_adjust

        true_estimates = sum(
            math.log(predict_probability(c, b0, b1, b2, b3))
            for c in color_samples
            if c.dark_or_light == 1
        )
        false_estimate = sum(
            math.log(1 - predict_probability(c, b0, b1, b2, b3))
            for c in color_samples
            if c.dark_or_light == 0
        )
        total_likelihood = true_estimates + false_estimate

        if best_likelihood < total_likelihood:
            best_likelihood = total_likelihood
            if i % 1000 == 0:
                print(best_likelihood)
        else:
            if random_b == 0:
                b0 -= random_adjust
            elif random_b == 1:
                b1 -= random_adjust
            elif random_b == 2:
                b2 -= random_adjust
            else:
                b3 -= random_adjust

    return b0, b1, b2, b3


def plot(color_samples, b0, b1, b2, b3):
    # Plot the data with results in 3D
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    # Extract data for plotting
    x1 = [sample.red for sample in color_samples]
    x2 = [sample.green for sample in color_samples]
    x3 = [sample.blue for sample in color_samples]
    y = [sample.dark_or_light for sample in color_samples]

    # Scatter plot of the data points
    ax.scatter(x1, x2, x3, c=y, cmap='viridis', marker='o')

    # Create a meshgrid for the plane
    x1_range = np.linspace(min(x1), max(x1), 10)
    x2_range = np.linspace(min(x2), max(x2), 10)
    x1_grid, x2_grid = np.meshgrid(x1_range, x2_range)
    x3_grid = (-b0 - b1 * x1_grid - b2 * x2_grid) / b3

    # Plot the decision boundary plane
    ax.plot_surface(x1_grid, x2_grid, x3_grid, color='r', alpha=0.5)

    ax.set_xlabel('X1')
    ax.set_ylabel('X2')
    ax.set_zlabel('X3')
    plt.show()


# Interact and test with new colors
def predict_font_shade(c, b0, b1, b2, b3):
    if predict_probability(c, b0, b1, b2, b3) >= 0.5:
        return "DARK"
    else:
        return "LIGHT"


if __name__ == '__main__':
    color_samples = [
        ColorSample(color[0], color[1], color[2], color[3])
        for index, color in pd.read_csv('color_samples.txt').iterrows()
    ]
    b0, b1, b2, b3 = build_model(color_samples)
    print(b0, b1, b2, b3)
    plot(color_samples, b0, b1, b2, b3)
    # while True:
    #     n = input("Predict light or dark font. Input values R,G,B: ")
    #     (r, g, b) = n.split(",")
    #     c = ColorSample(int(r), int(g), int(b), 0)
    #     print(predict_font_shade(c, b0, b1, b2, b3))
