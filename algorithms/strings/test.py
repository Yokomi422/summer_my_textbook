with open("./text.txt", "r") as f:
    text = f.read()

for t in text:
    if t != "a":
        print(t)