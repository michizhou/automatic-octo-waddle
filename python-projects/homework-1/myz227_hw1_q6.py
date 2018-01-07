class Vector:
    def __init__(self, d):
        if isinstance(d, list) == True:
            self.coords = d
        else:
            self.coords = [0]*d
    def __len__(self):
        return len(self.coords)
    def __getitem__(self, j):
        return self.coords[j]
    def __setitem__(self, j, val):
        self.coords[j] = val
    def __add__(self, other):
        if (len(self) != len(other)):
            raise ValueError("dimensions must agree")
        result = Vector(len(self))
        for j in range(len(self)):
            result[j] = self[j] + other[j]
        return result
    def __sub__(self, other):   # Part b implementation
        if (len(self) != len(other)):
            raise ValueError("Dimensions Must Agree")
        diff_vector = Vector(len(self))
        for j in range(len(self)):
            diff_vector[j] = self[j] - other[j]
        return diff_vector
    def __neg__(self):          # Part c implementation
        neg_vector = Vector(len(self))
        for index in range(len(self)):
            neg_vector[index] = self[index] * -1
        return neg_vector
    def __mul__(self, k):       # Parts d and f implementation
        if (isinstance(k, Vector) == True):
            product = 0
            for i in range(len(self)):
                product += self[i] * k[i]
        else:
            product = Vector(len(self))
            for index in range(len(self)):
                product[index] = self[index] * k
        return product
    def __rmul__(self, k):      # Part e implementation
        rtri_vector = Vector(len(self))
        for index in range(len(self)):
            rtri_vector[index] = k * self[index]
        return rtri_vector
    def __eq__(self, other):
        return self.coords == other.coords
    def __ne__(self, other):
        return not (self == other)
    def __str__(self):
        return '<' + str(self.coords)[1:-1] + '>'
    def __repr__(self):
        return str(self)
