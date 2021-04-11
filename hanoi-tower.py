from queue import LifoQueue as Stack


def move_disk(n_disk, source, target, temp):
    if n_disk == 1:
        print(f'Move disk from {source} to {target}')

    else:
        move_disk(n_disk-1, source, temp, target)
        move_disk(1, source, target, temp)
        move_disk(n_disk-1, temp, target, source)


def move_disk_without_recursion(n_disk, source, target, temp):
    stack = Stack()
    stack.put((n_disk, source, target, temp))

    while not stack.empty():
        n_disk, source, target, temp = stack.get()
        if n_disk == 1:
            print(f'Move disk from {source} to {target}')

        else:
            # Fist in first out
            stack.put((n_disk-1, temp, target, source))
            stack.put((1, source, target, temp))
            stack.put((n_disk-1, source, temp, target))

if __name__ == '__main__':
    print("Hanoi's town with recursion")
    move_disk(3, 'source', 'target', 'temp')

    print("\n=================================\n")

    print("Hanoi's town without recursion")
    move_disk_without_recursion(3, 'source', 'target', 'temp')