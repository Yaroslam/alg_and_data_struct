class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if(self.isEmpty() == 0):
            return None
        return self.stack.pop()

    def isEmpty(self):
        return len(self.stack)

    def get_top(self):
        return self.stack[-1]