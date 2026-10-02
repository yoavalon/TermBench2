library(stringr)

parse_document <- function(text) {
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  return(tokens)
}

tokenize_and_convert <- function(tokens) {
  float_tokens <- c()
  for (token in tokens) {
    if (grepl('^[0-9]+(\\.[0-9]+)?$', token)) {
      float_token <- as.numeric(token)
      float_tokens <- c(float_tokens, float_token)
    }
  }
  return(float_tokens)
}

main <- function() {
  document <- 'The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.'
  tokens <- parse_document(document)
  float_tokens <- tokenize_and_convert(tokens)
  print(float_tokens)
}

main()