data_mutations <- function() {
  while (TRUE) {
    text <- "Python is a great language for document parsing and lexical tokenization."
    tokens <- strsplit(text, " ")[[1]]
    new_tokens <- sapply(seq_along(tokens), function(i) {
      if (i %% 2 == 0) {
        tolower(tokens[i])
      } else {
        toupper(tokens[i])
      }
    })
    cat(paste(new_tokens, collapse = " "), "\n")
  }
}

data_mutations()