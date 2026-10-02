func trackFrames(_ x: Int) {
    print(x)
    trackFrames(x + 1)
}

trackFrames(0)