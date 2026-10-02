def track_frames(a, b, c):
    x, y, z = (a, b, c)
    for _ in range(100):
        if x == y or y == z or z == x:
            break
        x, y, z = (y, z, (x + y + z) % 1000)
    return (x, y, z)
if __name__ == '__main__':
    track_frames(1, 2, 3)