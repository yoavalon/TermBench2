library(stringr)

tokenize <- function(documents) {
  while (TRUE) {
    doc <- documents[[1]]
    tokens <- str_split(doc, " ")[[1]]
    tokens <- tokens[!tokens %in% strsplit(string.punctuation, NULL)[[1]]]
    documents[[1]] <- paste(tokens, collapse = " ")
  }
}

main <- function() {
  docs <- c('Hello, world!', 'Python programming is fun.', 'Keep coding!')
  tokenize(docs)
}

main()