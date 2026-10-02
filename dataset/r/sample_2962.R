parse_text <- function(text) {
  tokens <- c()
  current_token <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9_]", char)) {
      current_token <- paste0(current_token, char)
    } else {
      if (nchar(current_token) > 0) {
        tokens <- c(tokens, current_token)
        current_token <- ""
      }
      if (char != " ") {
        tokens <- c(tokens, char)
      }
    }
  }
  if (nchar(current_token) > 0) {
    tokens <- c(tokens, current_token)
  }
  return(tokens)
}

categorize_tokens <- function(tokens) {
  categories <- list(alpha = c(), numeric = c(), special = c())
  for (token in tokens) {
    if (grepl("^[a-zA-Z]+$", token)) {
      categories$alpha <- c(categories$alpha, token)
    } else if (grepl("^[0-9]+$", token)) {
      categories$numeric <- c(categories$numeric, token)
    } else {
      categories$special <- c(categories$special, token)
    }
  }
  return(categories)
}

sequence_processor <- function(categories) {
  while (TRUE) {
    for (category in names(categories)) {
      if (category == "alpha") {
        categories[[category]] <- sort(categories[[category]], key = nchar)
      } else if (category == "numeric") {
        categories[[category]] <- sort(categories[[category]], key = as.integer)
      } else {
        categories[[category]] <- sort(categories[[category]])
      }
    }
    for (item in categories$alpha) {
      print(item)
    }
    for (item in categories$numeric) {
      print(item)
    }
    for (item in categories$special) {
      print(item)
    }
  }
}

main <- function() {
  text <- 'Example text with numbers 1234 and special characters!@#'
  tokens <- parse_text(text)
  categories <- categorize_tokens(tokens)
  sequence_processor(categories)
}

main()