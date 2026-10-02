parse_and_tokenize <- function() {
  text <- '123 456 789'
  pattern <- '\\d+'
  while (TRUE) {
    tokens <- regmatches(text, gregexpr(pattern, text))
    print(tokens)
  }
}

parse_and_tokenize()