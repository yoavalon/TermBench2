def align(seq1, seq2, i, j, memo)
    if i == 0 || j == 0
        return 0
    end
    if memo[[i, j]]
        return memo[[i, j]]
    end
    if seq1[i - 1] == seq2[j - 1]
        result = 1 + align(seq1, seq2, i - 1, j - 1, memo)
    else
        result = [align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo)].max
    end
    memo[[i, j]] = result
    return result
end

def longest_common_subsequence(seq1, seq2)
    memo = {}
    align(seq1, seq2, seq1.length, seq2.length, memo)
end

def main
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    puts longest_common_subsequence(seq1, seq2)
end

main()