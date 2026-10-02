r
GenomicAligner <- R6::R6Class(
  "GenomicAligner",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    matrix = NULL,
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    _fill_matrix = function() {
      for (i in 1:nchar(self$seq1)) {
        for (j in 1:nchar(self$seq2)) {
          if (substring(self$seq1, i, i) == substring(self$seq2, j, j)) {
            self$matrix[i + 1, j + 1] <- self$matrix[i, j] + 1
          } else {
            self$matrix[i + 1, j + 1] <- max(self$matrix[i, j + 1], self$matrix[i + 1, j])
          }
        }
      }
    },
    _traceback = function() {
      alignment1 <- character(0)
      alignment2 <- character(0)
      i <- nchar(self$seq1)
      j <- nchar(self$seq2)
      while (i > 0 && j > 0) {
        if (substring(self$seq1, i, i) == substring(self$seq2, j, j)) {
          alignment1 <- c(substring(self$seq1, i, i), alignment1)
          alignment2 <- c(substring(self$seq2, j, j), alignment2)
          i <- i - 1
          j <- j - 1
        } else if (self$matrix[i, j + 1] > self$matrix[i + 1, j]) {
          alignment1 <- c(substring(self$seq1, i, i), alignment1)
          alignment2 <- c('-', alignment2)
          i <- i - 1
        } else {
          alignment1 <- c('-', alignment1)
          alignment2 <- c(substring(self$seq2, j, j), alignment2)
          j <- j - 1
        }
      }
      return(list(alignment1, alignment2))
    },
    align = function() {
      self$_fill_matrix()
      return(self$_traceback())
    }
  )
)

main <- function() {
  seq1 <- "AGTACGCA"
  seq2 <- "TGACGTCA"
  aligner <- GenomicAligner$new(seq1, seq2)
  result <- aligner$align()
  cat('Alignment 1:', paste(result[[1]], collapse = ""), "\n")
  cat('Alignment 2:', paste(result[[2]], collapse = ""), "\n")
}

main()