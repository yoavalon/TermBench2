parse_doc <- function(x) {
  if (length(x) > 0) {
    token <- x[1]
    print(token)
    parse_doc(x[-1])
  } else {
    parse_doc(x)
  }
}

tokenize <- function(text) {
  words <- strsplit(text, " ")[[1]]
  parse_doc(words)
}

tokenize('This is a non-terminating recursion example')