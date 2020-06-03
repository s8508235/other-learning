def main():
    N = input('Input:')
    try:
        N = int(N)
    except ValueError:
        print('please input number')
        return
    if N < 1:
        print('please input number > 1')
        return
    ans_list = [x for x in range(1, N+1)]
    print('所有數字是:', ", ".join(map(str, ans_list)))
    three = [x for x in range(1, N+1) if x % 3 == 0 and x % 5 != 0]
    five = [x for x in range(1, N+1) if x % 5 == 0 and x % 3 != 0]
    fifteen = [x for x in range(1, N+1) if x % 15 == 0]
    print('其中', ", ".join(map(str, three)), "; 被剃除",
          ", ".join(map(str, five)), ";被剃除 但是", ", ".join(map(str,fifteen)), "被保留")
    print("所以剩下來的數字是",  ", ".join(map(str,[num for num in ans_list if num not in three and num not in five])) ,"因此")
    print(f'Output: {len(ans_list) - len(three) - len(five)}')

if __name__ == "__main__":
    main()
