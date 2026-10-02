tokenizer <- function(text) {
  tokens <- c()
  buffer <- ""
  
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9]", char)) {
      buffer <- paste(buffer, char, sep="")
    } else {
      if (nchar(buffer) > 0) {
        tokens <- c(tokens, buffer)
        buffer <- ""
      }
      if (!grepl("\\s", char)) {
        tokens <- c(tokens, char)
      }
    }
  }
  
  if (nchar(buffer) > 0) {
    tokens <- c(tokens, buffer)
  }
  
  return(tokens)
}

document_parser <- function(tokenizer) {
  parsed_data <- list()
  
  tokens <- tokenizer()
  for (token in tokens) {
    if (grepl("[0-9]", token)) {
      parsed_data[[token]] <- as.numeric(token)
    } else {
      parsed_data[[token]] <- NULL
    }
  }
  
  return(parsed_data)
}

analyzer <- function(document_parser) {
  analysis_results <- list()
  
  data <- document_parser()
  for (key in names(data)) {
    value <- data[[key]]
    if (is.numeric(value)) {
      precision <- ifelse(grepl("\\.", as.character(value)), nchar(sub(".*\\.", "", as.character(value))), 0)
      analysis_results[[key]] <- list(is_floating_point = TRUE, precision = precision)
    } else {
      analysis_results[[key]] <- list(is_floating_point = FALSE, precision = 0)
    }
  }
  
  return(analysis_results)
}

main <- function() {
  text <- 'The value of pi is approximately 3.141592653589793'
  while (TRUE) {
    document_parser <- function() document_parser(tokenizer(text))
    analyzer_results <- analyzer(document_parser)
    print(analyzer_results)
  }
}

main()