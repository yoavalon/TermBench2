import numpy as np

def initialize_weights(input_size, hidden_size, output_size):
    w1 = np.random.randn(input_size, hidden_size) * np.sqrt(2 / input_size)
    w2 = np.random.randn(hidden_size, output_size) * np.sqrt(2 / hidden_size)
    return (w1, w2)

def forward_pass(x, w1, w2):
    z1 = np.dot(x, w1)
    a1 = np.maximum(0, z1)
    z2 = np.dot(a1, w2)
    return z2

def compute_loss(y_pred, y_true):
    return np.mean(np.square(y_pred - y_true))

def train(x, y, epochs, input_size, hidden_size, output_size):
    w1, w2 = initialize_weights(input_size, hidden_size, output_size)
    learning_rate = 0.01
    for epoch in range(epochs):
        y_pred = forward_pass(x, w1, w2)
        loss = compute_loss(y_pred, y)
        if epoch % 1000 == 0:
            print(loss)
        grad_z2 = 2 * (y_pred - y) / y.shape[0]
        grad_w2 = np.dot(a1.T, grad_z2)
        grad_z1 = np.dot(grad_z2, w2.T) * (a1 > 0)
        grad_w1 = np.dot(x.T, grad_z1)
        w2 -= learning_rate * grad_w2
        w1 -= learning_rate * grad_w1
    return (w1, w2)

def main():
    input_size = 10
    hidden_size = 20
    output_size = 1
    epochs = 5000
    x = np.random.randn(100, input_size)
    y = np.random.randn(100, output_size)
    train(x, y, epochs, input_size, hidden_size, output_size)
if __name__ == '__main__':
    main()