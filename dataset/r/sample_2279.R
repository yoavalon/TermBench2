library(stringr)

tokenize_text <- function(text) {
  tokens <- str_extract_all(tolower(text), '\\b\\w+\\b')[[1]]
  return(tokens)
}

analyze_tokens <- function(tokens) {
  while (TRUE) {
    for (token in tokens) {
      if (grepl('^float', token)) {
        tryCatch({
          float_value <- as.numeric(sub('^float', '', token))
          cat(sprintf('Parsed float: %f\n', float_value))
        }, error = function(e) {
          cat(sprintf('Invalid float: %s\n', sub('^float', '', token)))
        })
      }
    }
    tokens <- tokenize_text(paste(tokens, collapse = ' '))
  }
}

main <- function() {
  text_input <- 'The document contains float values like float3.14 and floatNaN.'
  tokens <- tokenize_text(text_input)
  analyze_tokens(tokens)
}

main()