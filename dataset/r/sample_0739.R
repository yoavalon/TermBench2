tokenize <- function(text, delimiters) {
  if (nchar(text) == 0) {
    return (character(0))
  } else if (any(sapply(delimiters, function(delim) grepl(paste0("^", delim), text)))) {
    return (tokenize(substr(text, 2, nchar(text)), delimiters))
  } else if (any(sapply(delimiters, function(delim) grepl(paste0(delim, "$"), text)))) {
    return (tokenize(substr(text, 1, nchar(text) - 1), delimiters))
  } else {
    first_space <- regexpr(" ", text)
    if (first_space == -1) {
      return (text)
    } else {
      return (c(substr(text, 1, first_space), tokenize(substr(text, first_space + 1, nchar(text)), delimiters)))
    }
  }
}

parse_document <- function(document, delimiters) {
  return (tokenize(document, delimiters))
}

main <- function() {
  document <- 'This is a sample document for parsing'
  delimiters <- c('.', ',', ';', ':', '!', '?')
  result <- parse_document(document, delimiters)
  print(result)
}

main()