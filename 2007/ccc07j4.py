s = input()
t = input()
al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
flag = True
for letter in al:
    if s.count(letter) != t.count(letter):
        flag = False
        break
print("Is not an anagram.") if not flag else print("Is an anagram.")
