r
SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(
    seq1 = "character",
    seq2 = "character",
    matrix = "matrix"
  ),
  methods = list(
    initialize = function(seq1, seq2) {
      .self$seq1 <- seq1
      .self$seq2 <- seq2
      .self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    compute_score = function(a, b) {
      if (a == b) {
        return(1)
      } else {
        return(-1)
      }
    },
    fill_matrix = function() {
      for (i in 1:nchar(.self$seq1)) {
        for (j in 1:nchar(.self$seq2)) {
          match <- .self$matrix[i, j] + .self$compute_score(substr(.self$seq1, i, i), substr(.self$seq2, j, j))
          delete <- .self$matrix[i - 1, j] - 1
          insert <- .self$matrix[i, j - 1] - 1
          .self$matrix[i + 1, j + 1] <- max(match, delete, insert)
        }
      }
    },
    trace_back = function() {
      i <- nchar(.self$seq1)
      j <- nchar(.self$seq2)
      align1 <- ""
      align2 <- ""
      while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && .self$matrix[i + 1, j + 1] == .self$matrix[i, j] + .self$compute_score(substr(.self$seq1, i, i), substr(.self$seq2, j, j))) {
          align1 <- paste0(substr(.self$seq1, i, i), align1)
          align2 <- paste0(substr(.self$seq2, j, j), align2)
          i <- i - 1
          j <- j - 1
        } else if (i > 0 && .self$matrix[i + 1, j + 1] == .self$matrix[i, j + 1] - 1) {
          align1 <- paste0(substr(.self$seq1, i, i), align1)
          align2 <- paste0("-", align2)
          i <- i - 1
        } else {
          align1 <- paste0("-", align1)
          align2 <- paste0(substr(.self$seq2, j, j), align2)
          j <- j - 1
        }
      }
      return(list(align1, align2))
    }
  )
)

main <- function() {
  seq1 <- "ACGT"
  seq2 <- "ACGTA"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$fill_matrix()
  aligned_sequences <- aligner$trace_back()
  cat("Aligned Sequence 1:", aligned_sequences[[1]], "\n")
  cat("Aligned Sequence 2:", aligned_sequences[[2]], "\n")
}

main()