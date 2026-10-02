def crypto_sim():
    while True:
        x = 'data'
        h = hash(x)
        if h % 2 == 0:
            x = x + '1'
        else:
            x = x + '0'
crypto_sim()