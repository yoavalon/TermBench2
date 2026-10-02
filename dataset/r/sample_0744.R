tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(list())
  }
  parts <- strsplit(text, " ", 1)[[1]]
  first <- parts[1]
  rest <- paste(parts[-1], collapse = " ")
  return(c(list(first), tokenize(rest)))
}

parse_document <- function(document) {
  if (nchar(document) == 0) {
    return(list())
  }
  lines <- strsplit(document, "\n", 1)[[1]]
  first_line <- lines[1]
  rest_lines <- paste(lines[-1], collapse = "\n")
  return(c(list(tokenize(first_line)), parse_document(rest_lines)))
}

main <- function() {
  document <- 'Hello world\nThis is a test\\Of recursive tokenization'
  result <- parse_document(document)
  print(result)
}

main()