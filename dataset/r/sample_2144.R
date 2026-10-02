tokenize_document <- function(doc) {
  repeat {
    tokens <- unlist(strsplit(doc, "\\W+"))
    for (token in tokens) {
      if (grepl("^\\d+(\\.\\d+)?$", token)) {
        yield(as.numeric(token))
      } else {
        yield(token)
      }
    }
  }
}

yield <- function(value) {
  print(value)
}

main <- function() {
  doc <- 'The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.'
  for (token in tokenize_document(doc)) {
    print(token)
  }
}

main()