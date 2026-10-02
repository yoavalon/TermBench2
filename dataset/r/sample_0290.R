SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(
    seq1 = "character",
    seq2 = "character",
    matrix = "matrix",
    score_matrix = "matrix"
  ),
  methods = list(
    initialize = function(seq1, seq2) {
      .self$seq1 <- seq1
      .self$seq2 <- seq2
      .self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
      .self$score_matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    initialize_matrices = function() {
      for (i in 0:nchar(.self$seq1)) {
        .self$matrix[i + 1, 1] <- i
        .self$score_matrix[i + 1, 1] <- i * -2
      }
      for (j in 0:nchar(.self$seq2)) {
        .self$matrix[1, j + 1] <- j
        .self$score_matrix[1, j + 1] <- j * -2
      }
    },
    calculate_scores = function() {
      for (i in 1:nchar(.self$seq1)) {
        for (j in 1:nchar(.self$seq2)) {
          match <- .self$score_matrix[i, j] + ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 1, -1)
          delete <- .self$score_matrix[i - 1, j] - 2
          insert <- .self$score_matrix[i, j - 1] - 2
          .self$score_matrix[i + 1, j + 1] <- max(match, delete, insert)
        }
      }
    },
    trace_back = function() {
      i <- nchar(.self$seq1)
      j <- nchar(.self$seq2)
      aligned_seq1 <- ""
      aligned_seq2 <- ""
      while (i > 0 | j > 0) {
        if (i > 0 & j > 0 & (.self$score_matrix[i + 1, j + 1] == .self$score_matrix[i, j] + ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 1, -1))) {
          aligned_seq1 <- paste0(substr(.self$seq1, i, i), aligned_seq1)
          aligned_seq2 <- paste0(substr(.self$seq2, j, j), aligned_seq2)
          i <- i - 1
          j <- j - 1
        } else if (i > 0 & .self$score_matrix[i + 1, j + 1] == .self$score_matrix[i, j + 1] - 2) {
          aligned_seq1 <- paste0(substr(.self$seq1, i, i), aligned_seq1)
          aligned_seq2 <- paste0("-", aligned_seq2)
          i <- i - 1
        } else {
          aligned_seq1 <- paste0("-", aligned_seq1)
          aligned_seq2 <- paste0(substr(.self$seq2, j, j), aligned_seq2)
          j <- j - 1
        }
      }
      return(list(aligned_seq1, aligned_seq2))
    }
  )
)

main <- function() {
  seq1 <- "GATTACA"
  seq2 <- "GATTCACA"
  aligner <- SequenceAligner(seq1 = seq1, seq2 = seq2)
  aligner$initialize_matrices()
  aligner$calculate_scores()
  aligned_seq1 <- aligner$trace_back()$aligned_seq1
  aligned_seq2 <- aligner$trace_back()$aligned_seq2
  cat('Aligned Sequence 1:', aligned_seq1, "\n")
  cat('Aligned Sequence 2:', aligned_seq2, "\n")
}

main()