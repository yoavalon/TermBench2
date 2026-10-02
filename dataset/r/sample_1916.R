library(stringr)

tokenize_document <- function(doc) {
  tokens <- str_extract_all(doc, '\\b\\w+\\b')[[1]]
  return(tokens)
}

analyze_token_precision <- function(tokens) {
  precision_values <- c()
  for (token in tokens) {
    if (grepl('^\\d+\\.\\d+$', token)) {
      float_value <- as.numeric(token)
      precision <- nchar(strsplit(as.character(float_value), '\\.')[[1]][2])
      precision_values <- c(precision_values, precision)
    }
  }
  return(precision_values)
}

main <- function() {
  document <- 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.'
  tokens <- tokenize_document(document)
  precision_values <- analyze_token_precision(tokens)
  print(precision_values)
}

main()