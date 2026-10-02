Alignment <- R6::R6Class("Alignment",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    len1 = NULL,
    len2 = NULL,
    
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$len1 <- nchar(seq1)
      self$len2 <- nchar(seq2)
    },
    
    score = function(i, j) {
      if (substr(self$seq1, i, i) == substr(self$seq2, j, j)) 1 else -1
    },
    
    align = function(i, j) {
      if (i == -1 || j == -1) {
        return(list(0, ""))
      }
      match <- self$align(i - 1, j - 1)[[1]]
      match <- match + self$score(i, j)
      align1 <- self$align(i - 1, j - 1)[[2]]
      align2 <- self$align(i - 1, j - 1)[[3]]
      
      insert <- self$align(i, j - 1)[[1]]
      align1_ins <- self$align(i, j - 1)[[2]]
      align2_ins <- self$align(i, j - 1)[[3]]
      insert <- insert - 1
      
      delete <- self$align(i - 1, j)[[1]]
      align1_del <- self$align(i - 1, j)[[2]]
      align2_del <- self$align(i - 1, j)[[3]]
      delete <- delete - 1
      
      if (match >= insert && match >= delete) {
        return(list(match, paste0(substr(self$seq1, i, i), align1), paste0(substr(self$seq2, j, j), align2)))
      } else if (insert >= match && insert >= delete) {
        return(list(insert, paste0("_", align1_ins), paste0(substr(self$seq2, j, j), align2_ins)))
      } else {
        return(list(delete, paste0(substr(self$seq1, i, i), align1_del), paste0("_", align2_del)))
      }
    }
  )
)

main <- function() {
  sequence1 <- 'AGGTAB'
  sequence2 <- 'GXTXAYB'
  alignment <- Alignment$new(sequence1, sequence2)
  result <- alignment$align(alignment$len1, alignment$len2)
  cat('Aligned Sequence 1:', result[[2]], '\n')
  cat('Aligned Sequence 2:', result[[3]], '\n')
}

main()