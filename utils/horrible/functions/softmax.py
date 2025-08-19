"""
softmax.py

  z = [z1, z2, z3, ..., zK]
  K = number of elements in input vector

  softmax(z) = (e ** zi) / sum(e ** z1, e ** z2, ..., e ** zK)

"""



import numpy as np


class Softmax:
  def __init__(self, input_vector):
    self.len = len(input_vector)
    self.result = (np.e ** input_vector) / np.sum(np.e ** input_vector)

  def __str__(self):
    return f'{self.result}'

  def __len__(self):
    return len(self.result)
  
  def __getitem__(self, i):
    return self.result[i]
  
  @staticmethod
  def softmax(input_vector):
    return (np.e ** np.array(input_vector)) / np.sum(np.e ** np.array(input_vector))
  

softmax = Softmax(np.array([2.0, 1.0, 0.1]))
print(softmax)

print(len(softmax))
print(softmax[0])


print(Softmax.softmax([2.0, 1.0, 0.1]))