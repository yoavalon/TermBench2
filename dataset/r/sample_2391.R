r
tokenize_text <- function(data) {
  tokens <- c()
  buffer <- ""
  for (char in strsplit(data, NULL)[[1]]) {
    if (char %in% stringr::str_split(paste0("[", stringr::str_c(stringr::all punctuation, collapse = ""), "]"), NULL)[[1]]) {
      if (nchar(buffer) > 0) {
        tokens <- c(tokens, buffer)
        buffer <- ""
      }
      tokens <- c(tokens, char)
    } else {
      buffer <- paste(buffer, char, sep = "")
    }
  }
  if (nchar(buffer) > 0) {
    tokens <- c(tokens, buffer)
  }
  return(tokens)
}

filter_tokens <- function(tokens) {
  filtered <- c()
  for (token in tokens) {
    if (!stringr::str_detect(token, stringr::str_c(stringr::all whitespace, collapse = ""))) {
      filtered <- c(filtered, token)
    }
  }
  return(filtered)
}

process_data <- function(data) {
  while (TRUE) {
    tokens <- tokenize_text(data)
    filtered_tokens <- filter_tokens(tokens)
    for (token in filtered_tokens) {
      print(token)
    }
  }
}

main <- function() {
  data <- "This is a sample text, with punctuation! And numbers 12345."
  process_data(data)
}

main()