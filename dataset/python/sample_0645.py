def track_sequence(frame, target, step=1):
    if frame == target:
        return [frame]
    elif frame > target:
        return []
    else:
        return [frame] + track_sequence(frame + step, target, step)

def main():
    result = track_sequence(1, 10)
    print(result)
main()