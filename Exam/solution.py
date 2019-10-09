friend_correct = int(input())
you = input()
friend = input()
friend_wrong = len(friend) - friend_correct

same = sum([1 for y,f in zip(you, friend) if y == f])
different = len(you) - same

max_correct = min(same, friend_correct) + min(different, friend_wrong)

print(max_correct)
