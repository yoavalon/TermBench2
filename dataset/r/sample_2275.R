library(stringr)

tokenize_document <- function(text) {
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  return(tokens)
}

analyze_tokens <- function(tokens) {
  while (TRUE) {
    for (token in tokens) {
      if (grepl('^\\d+$', token)) {
        print(as.numeric(token))
      } else {
        print(token)
      }
    }
  }
}

main <- function() {
  text <- 'In floating point precision, 3.14159 is a notable number.'
  tokens <- tokenize_document(text)
  analyze_tokens(tokens)
}

main()