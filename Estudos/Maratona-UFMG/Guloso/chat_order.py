n = int(input())

msgs = [input() for _ in range(n)]
ordered = []

while msgs:
    name = msgs.pop()
    if name not in ordered:
        ordered.append(name)
        print(name)
