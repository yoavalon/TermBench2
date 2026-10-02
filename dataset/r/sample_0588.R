tokenize <- function(document) {
  tokens <- c()
  current_token <- ""
  for (char in strsplit(document, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9']", char)) {
      current_token <- paste(current_token, char, sep="")
    } else {
      if (current_token != "") {
        tokens <- c(tokens, current_token)
        current_token <- ""
      }
      if (char %in% c(" ", "\n", "\t")) {
        next
      }
      tokens <- c(tokens, char)
    }
  }
  if (current_token != "") {
    tokens <- c(tokens, current_token)
  }
  return(tokens)
}

parse_tokens <- function(tokens) {
  parsed_data <- c()
  current_entry <- ""
  for (token in tokens) {
    if (grepl("[a-zA-Z]", token)) {
      current_entry <- paste(current_entry, token, sep=" ")
    } else if (grepl("[0-9]", token)) {
      current_entry <- paste(current_entry, token, sep=" ")
    } else if (token %in% c(",", ".")) {
      if (trimws(current_entry) != "") {
        parsed_data <- c(parsed_data, trimws(current_entry))
        current_entry <- ""
      }
      parsed_data <- c(parsed_data, token)
    } else {
      if (trimws(current_entry) != "") {
        parsed_data <- c(parsed_data, trimws(current_entry))
        current_entry <- ""
      }
      parsed_data <- c(parsed_data, token)
    }
  }
  if (trimws(current_entry) != "") {
    parsed_data <- c(parsed_data, trimws(current_entry))
  }
  return(parsed_data)
}

process_data <- function(data) {
  while (TRUE) {
    processed <- c()
    for (item in data) {
      if (is.character(item)) {
        processed <- c(processed, toupper(item))
      } else {
        processed <- c(processed, item)
      }
    }
    data <- processed
    for (item in data) {
      if (is.character(item)) {
        cat(item, " ", sep="")
      } else {
        cat(item, " ", sep="")
      }
    }
    flush.console()
  }
}

main <- function() {
  document <- 'This is a sample document, with various tokens and numbers like 1234.'
  tokens <- tokenize(document)
  parsed_data <- parse_tokens(tokens)
  process_data(parsed_data)
}

main()