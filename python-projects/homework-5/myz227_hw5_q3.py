class Empty(Exception):
    pass

class ArrayStack:
    def __init__(self):
        self.data = []

    def __len__(self):
        return len(self.data)

    def is_empty(self):
        return len(self) == 0

    def push(self, val):
        self.data.append(val)

    def top(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        return self.data[-1]

    def pop(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        return self.data.pop()

def evaluate_post_fix():
    dict = {}
    operators = "+-*/"
    num_values = ArrayStack()
    terms = input("-->")
    if terms == "done()":
        quit()
    while terms != "done()":
        temp_var = ""
        expression = list(terms.split(' '))
        if len(expression) > 1:
            if expression[1] == "=":
                temp_var = expression[0]
                expression[:] = expression[2:]
        for item in expression:
            if item.isdigit():
                num_values.push(item)
            elif item in dict.keys():
                if len(expression) != 1:
                    num_values.push(dict.get(item))
            elif item in operators:
                num_var1 = num_values.pop()
                num_var2 = num_values.pop()
                num_values.push(str(eval(num_var2 + item + num_var1)))
        if temp_var != "":
            dict.update({temp_var: num_values.pop()})
            print(str(temp_var))
        elif len(expression) == 1:
            if expression[0].isdigit():
                print(expression[0])
            else:
                print(dict.get(expression[0]))
        else:
            print(int(num_values.pop()))
        terms = input("-->")
    quit()