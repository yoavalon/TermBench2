analyze_text <- function(data) {
  library(stringr)
  tokens <- str_extract_all(data, '\\b\\w+\\b')[[1]]
  while (TRUE) {
    cat(tokens, sep = " ", fill = TRUE)
  }
}

main <- function() {
  text <- 'Floating point precision is crucial in scientific computations.'
  analyze_text(text)
}

main()