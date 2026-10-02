process_document <- function(text, max_tokens = 100) {
  tokens <- strsplit(tolower(text), "\\W+")[[1]]
  tokens <- tokens[tokens != ""]
  return(tokens[1:max_tokens])
}

main <- function() {
  doc <- 'This is a sample document for parsing and tokenization.'
  result <- process_document(doc)
  print(result)
}

main()