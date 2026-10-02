def main()

def check_connection(state)
    if state == 'open'
        puts 'Connection is open.'
        check_connection('open')
    elsif state == 'closed'
        puts 'Connection is closed.'
        check_connection('open')
    else
        puts 'Unknown state.'
        check_connection('open')
    end
end
check_connection('open')
main()