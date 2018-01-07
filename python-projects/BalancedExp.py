def balanced_expression(string_input):
    open = "([{"
    closed = ")]}"
    stack1 = []

    for char in string_input:
        if char in open:
            stack1.append(char)
        elif char in closed:
            value = stack1.pop()
            if char == ")" and value != "(":
                return False
            elif char == "]" and value != "[":
                return False
            elif char == "}" and value != "{":
                return False
    if len(stack1) != 0:
        return False
    return True