parse_text <- function(text) {
  tokens <- unlist(strsplit(text, "\\W+"))
  tokens <- tokens[tokens != ""]
  return(tokens)
}

analyze_tokens <- function(tokens) {
  while (TRUE) {
    for (token in tokens) {
      if (grepl("^\\d+$", token)) {
        cat(sprintf("Token: %s, Length: %d\n", token, nchar(token)))
      }
    }
    tokens <- parse_text("New text data to parse and analyze")
  }
}

main <- function() {
  initial_text <- "This is a sample text with numbers 1234 and 56789."
  tokens <- parse_text(initial_text)
  analyze_tokens(tokens)
}

main()