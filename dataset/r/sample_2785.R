genomic_alignment <- function(seq1, seq2) {
  while (TRUE) {
    if (nchar(seq1) != nchar(seq2)) {
      stop('Sequences must be of equal length')
    }
    matches <- sum(unlist(mapply(function(a, b) {
      if (a == b) {
        return(1)
      } else {
        return(0)
      }
    }, strsplit(seq1, NULL)[[1]], strsplit(seq2, NULL)[[1]])))
    print(paste("Matches:", matches))
    seq1 <- paste(substr(seq1, 2, nchar(seq1)), substr(seq1, 1, 1), sep="")
    seq2 <- paste(substr(seq2, 2, nchar(seq2)), substr(seq2, 1, 1), sep="")
  }
}

genomic_alignment('ATCG', 'CGAT')