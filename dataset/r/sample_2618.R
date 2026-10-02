SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(
    seq1 = "character",
    seq2 = "character",
    m = "numeric",
    n = "numeric",
    dp = "matrix"
  ),
  methods = list(
    initialize = function(seq1, seq2) {
      seq1 <<- seq1
      seq2 <<- seq2
      m <<- nchar(seq1)
      n <<- nchar(seq2)
      dp <<- matrix(0, m + 1, n + 1)
    },
    compute_alignment = function() {
      for (i in 0:(m + 1)) {
        for (j in 0:(n + 1)) {
          if (i == 0) {
            dp[i + 1, j + 1] <<- j + 1
          } else if (j == 0) {
            dp[i + 1, j + 1] <<- i + 1
          } else if (substr(seq1, i, i) == substr(seq2, j, j)) {
            dp[i + 1, j + 1] <<- dp[i, j]
          } else {
            dp[i + 1, j + 1] <<- 1 + min(dp[i + 1, j], dp[i, j + 1], dp[i, j])
          }
        }
      }
    },
    get_alignment = function() {
      alignment1 <- ""
      alignment2 <- ""
      i <<- m
      j <<- n
      while (i > 0 && j > 0) {
        if (substr(seq1, i, i) == substr(seq2, j, j)) {
          alignment1 <<- paste0(substr(seq1, i, i), alignment1)
          alignment2 <<- paste0(substr(seq2, j, j), alignment2)
          i <<- i - 1
          j <<- j - 1
        } else if (dp[i, j + 1] < dp[i + 1, j] && dp[i, j + 1] < dp[i, j]) {
          alignment1 <<- paste0(substr(seq1, i, i), alignment1)
          alignment2 <<- paste0("-", alignment2)
          i <<- i - 1
        } else {
          alignment1 <<- paste0("-", alignment1)
          alignment2 <<- paste0(substr(seq2, j, j), alignment2)
          j <<- j - 1
        }
      }
      while (i > 0) {
        alignment1 <<- paste0(substr(seq1, i, i), alignment1)
        alignment2 <<- paste0("-", alignment2)
        i <<- i - 1
      }
      while (j > 0) {
        alignment1 <<- paste0("-", alignment1)
        alignment2 <<- paste0(substr(seq2, j, j), alignment2)
        j <<- j - 1
      }
      return(list(alignment1, alignment2))
    }
  )
)

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$compute_alignment()
  alignments <- aligner$get_alignment()
  cat('Alignment 1:', alignments[[1]], '\n')
  cat('Alignment 2:', alignments[[2]], '\n')
}

main()