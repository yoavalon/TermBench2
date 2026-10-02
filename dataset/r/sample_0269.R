SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(
    seq1 = "character",
    seq2 = "character",
    matrix = "matrix"
  ),
  methods = list(
    initialize = function(seq1, seq2) {
      seq1 <<- seq1
      seq2 <<- seq2
      matrix <<- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    initialize_matrix = function() {
      for (i in 0:nchar(seq1)) {
        matrix[i + 1, 1] <<- i
      }
      for (j in 0:nchar(seq2)) {
        matrix[1, j + 1] <<- j
      }
    },
    fill_matrix = function() {
      for (i in 1:nchar(seq1)) {
        for (j in 1:nchar(seq2)) {
          if (substr(seq1, i, i) == substr(seq2, j, j)) {
            cost <- 0
          } else {
            cost <- 1
          }
          matrix[i + 1, j + 1] <<- min(matrix[i, j + 1] + 1, matrix[i + 1, j] + 1, matrix[i, j] + cost)
        }
      }
    },
    trace_back = function() {
      i <<- nchar(seq1)
      j <<- nchar(seq2)
      align1 <<- ""
      align2 <<- ""
      while (i > 0 | j > 0) {
        if (i > 0 & j > 0 & substr(seq1, i, i) == substr(seq2, j, j)) {
          align1 <<- paste0(substr(seq1, i, i), align1)
          align2 <<- paste0(substr(seq2, j, j), align2)
          i <<- i - 1
          j <<- j - 1
        } else if (i > 0 & matrix[i + 1, j + 1] == matrix[i, j + 1] + 1) {
          align1 <<- paste0(substr(seq1, i, i), align1)
          align2 <<- paste0("-", align2)
          i <<- i - 1
        } else {
          align1 <<- paste0("-", align1)
          align2 <<- paste0(substr(seq2, j, j), align2)
          j <<- j - 1
        }
      }
      return(list(align1, align2))
    }
  )
)

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  aligner <- SequenceAligner(seq1, seq2)
  aligner$initialize_matrix()
  aligner$fill_matrix()
  aligned_sequences <- aligner$trace_back()
  cat("Aligned Sequence 1:", aligned_sequences[[1]], "\n")
  cat("Aligned Sequence 2:", aligned_sequences[[2]], "\n")
}

main()