SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(seq1 = "character", seq2 = "character", matrix = "matrix"),
  methods = list(
    initialize = function(seq1, seq2) {
      .self$seq1 <- seq1
      .self$seq2 <- seq2
      .self$matrix <- NULL
    },
    initialize_matrix = function() {
      len1 <- nchar(.self$seq1)
      len2 <- nchar(.self$seq2)
      .self$matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
      for (i in 0:len1) {
        .self$matrix[i + 1, 1] <- i
      }
      for (j in 0:len2) {
        .self$matrix[1, j + 1] <- j
      }
    },
    compute_alignment = function() {
      len1 <- nchar(.self$seq1)
      len2 <- nchar(.self$seq2)
      for (i in 1:len1) {
        for (j in 1:len2) {
          cost <- ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 0, 1)
          .self$matrix[i + 1, j + 1] <- min(
            .self$matrix[i, j + 1] + 1,
            .self$matrix[i + 1, j] + 1,
            .self$matrix[i, j] + cost
          )
        }
      }
    },
    backtrack_alignment = function() {
      i <- nchar(.self$seq1)
      j <- nchar(.self$seq2)
      align1 <- ""
      align2 <- ""
      while (i > 0 && j > 0) {
        if (substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
          align1 <- paste(substr(.self$seq1, i, i), align1, sep = "")
          align2 <- paste(substr(.self$seq2, j, j), align2, sep = "")
          i <- i - 1
          j <- j - 1
        } else if (.self$matrix[i, j + 1] + 1 == .self$matrix[i + 1, j + 1]) {
          align1 <- paste(substr(.self$seq1, i, i), align1, sep = "")
          align2 <- paste("-", align2, sep = "")
          i <- i - 1
        } else {
          align1 <- paste("-", align1, sep = "")
          align2 <- paste(substr(.self$seq2, j, j), align2, sep = "")
          j <- j - 1
        }
      }
      while (i > 0) {
        align1 <- paste(substr(.self$seq1, i, i), align1, sep = "")
        align2 <- paste("-", align2, sep = "")
        i <- i - 1
      }
      while (j > 0) {
        align1 <- paste("-", align1, sep = "")
        align2 <- paste(substr(.self$seq2, j, j), align2, sep = "")
        j <- j - 1
      }
      return(list(align1, align2))
    }
  )
)

main <- function() {
  seq1 <- 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA'
  seq2 <- 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'
  aligner <- SequenceAligner(seq1, seq2)
  aligner$initialize_matrix()
  aligner$compute_alignment()
  alignment <- aligner$backtrack_alignment()
  cat('Aligned Sequence 1:', alignment[[1]], "\n")
  cat('Aligned Sequence 2:', alignment[[2]], "\n")
}

main()