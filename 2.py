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
    ans_list = [x for x in range(1, N+1) if x % 3 != 0 and x % 5 != 0 or x % 15 == 0]
    print(f'Output: {len(ans_list)}')

if __name__ == "__main__":
    main()
