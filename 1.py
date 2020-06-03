import re
def f(input_string):
    ans = []
    for word in re.split(r'\s+',input_string):
        # print(word)
        ans.append(word[::-1])
    
    return ' '.join(ans)

txt = "welcome  to the jungle"
print(f(txt))
print(f('flipped class room is important'))