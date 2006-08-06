// $ANTLR 3.0b3 grammar/antlr_3/bc.g 2006-08-06 23:38:37

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class BcParserLexer extends Lexer {
    public static final int INTEGER=9;
    public static final int T14=14;
    public static final int MINUS=7;
    public static final int T15=15;
    public static final int EOF=-1;
    public static final int WS=11;
    public static final int NUMBER=8;
    public static final int STRING=5;
    public static final int Tokens=17;
    public static final int T16=16;
    public static final int PLUS=6;
    public static final int ML_COMMENT=10;
    public static final int T13=13;
    public static final int PROGRAM=4;
    public static final int NEWLINE=12;
    public BcParserLexer() {;} 
    public BcParserLexer(CharStream input) {
        super(input);
    }
    public String getGrammarFileName() { return "grammar/antlr_3/bc.g"; }

    // $ANTLR start T13
    public void mT13() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = T13;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:3:7: ( ';' )
            // grammar/antlr_3/bc.g:3:7: ';'
            {
            match(';'); 

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end T13

    // $ANTLR start T14
    public void mT14() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = T14;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:4:7: ( '(' )
            // grammar/antlr_3/bc.g:4:7: '('
            {
            match('('); 

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end T14

    // $ANTLR start T15
    public void mT15() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = T15;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:5:7: ( ')' )
            // grammar/antlr_3/bc.g:5:7: ')'
            {
            match(')'); 

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end T15

    // $ANTLR start T16
    public void mT16() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = T16;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:6:7: ( 'quit' )
            // grammar/antlr_3/bc.g:6:7: 'quit'
            {
            match("quit"); 


            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end T16

    // $ANTLR start NUMBER
    public void mNUMBER() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = NUMBER;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:64:5: ( INTEGER ( '.' INTEGER )? | '.' INTEGER )
            int alt2=2;
            int LA2_0 = input.LA(1);
            if ( ((LA2_0>='0' && LA2_0<='9')||(LA2_0>='A' && LA2_0<='F')) ) {
                alt2=1;
            }
            else if ( (LA2_0=='.') ) {
                alt2=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("63:1: NUMBER : ( INTEGER ( '.' INTEGER )? | '.' INTEGER );", 2, 0, input);

                throw nvae;
            }
            switch (alt2) {
                case 1 :
                    // grammar/antlr_3/bc.g:64:5: INTEGER ( '.' INTEGER )?
                    {
                    mINTEGER(); 
                    // grammar/antlr_3/bc.g:64:13: ( '.' INTEGER )?
                    int alt1=2;
                    int LA1_0 = input.LA(1);
                    if ( (LA1_0=='.') ) {
                        alt1=1;
                    }
                    switch (alt1) {
                        case 1 :
                            // grammar/antlr_3/bc.g:64:14: '.' INTEGER
                            {
                            match('.'); 
                            mINTEGER(); 

                            }
                            break;

                    }


                    }
                    break;
                case 2 :
                    // grammar/antlr_3/bc.g:66:5: '.' INTEGER
                    {
                    match('.'); 
                    mINTEGER(); 

                    }
                    break;

            }


                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end NUMBER

    // $ANTLR start INTEGER
    public void mINTEGER() throws RecognitionException {
        try {
            ruleNestingLevel++;
            // grammar/antlr_3/bc.g:71:5: ( ( ('0'..'9'|'A'..'F'))+ )
            // grammar/antlr_3/bc.g:71:5: ( ('0'..'9'|'A'..'F'))+
            {
            // grammar/antlr_3/bc.g:71:5: ( ('0'..'9'|'A'..'F'))+
            int cnt3=0;
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);
                if ( ((LA3_0>='0' && LA3_0<='9')||(LA3_0>='A' && LA3_0<='F')) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // grammar/antlr_3/bc.g:71:6: ('0'..'9'|'A'..'F')
            	    {
            	    if ( (input.LA(1)>='0' && input.LA(1)<='9')||(input.LA(1)>='A' && input.LA(1)<='F') ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse =
            	            new MismatchedSetException(null,input);
            	        recover(mse);    throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt3 >= 1 ) break loop3;
                        EarlyExitException eee =
                            new EarlyExitException(3, input);
                        throw eee;
                }
                cnt3++;
            } while (true);


            }

        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end INTEGER

    // $ANTLR start MINUS
    public void mMINUS() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = MINUS;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:75:5: ( '-' )
            // grammar/antlr_3/bc.g:75:5: '-'
            {
            match('-'); 

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end MINUS

    // $ANTLR start PLUS
    public void mPLUS() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = PLUS;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:79:5: ( '+' )
            // grammar/antlr_3/bc.g:79:5: '+'
            {
            match('+'); 

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end PLUS

    // $ANTLR start ML_COMMENT
    public void mML_COMMENT() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = ML_COMMENT;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:89:5: ( '/*' ( options {greedy=false; } : . )* '*/' )
            // grammar/antlr_3/bc.g:89:5: '/*' ( options {greedy=false; } : . )* '*/'
            {
            match("/*"); 

            // grammar/antlr_3/bc.g:89:10: ( options {greedy=false; } : . )*
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);
                if ( (LA4_0=='*') ) {
                    int LA4_1 = input.LA(2);
                    if ( (LA4_1=='/') ) {
                        alt4=2;
                    }
                    else if ( ((LA4_1>='\u0000' && LA4_1<='.')||(LA4_1>='0' && LA4_1<='\uFFFE')) ) {
                        alt4=1;
                    }


                }
                else if ( ((LA4_0>='\u0000' && LA4_0<=')')||(LA4_0>='+' && LA4_0<='\uFFFE')) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // grammar/antlr_3/bc.g:89:38: .
            	    {
            	    matchAny(); 

            	    }
            	    break;

            	default :
            	    break loop4;
                }
            } while (true);

            match("*/"); 


                  channel = 99;       // send into nirwana 
                

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end ML_COMMENT

    // $ANTLR start WS
    public void mWS() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = WS;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:97:5: ( ( (' '|'\\t'|'\\r'|'\\n'))+ )
            // grammar/antlr_3/bc.g:97:5: ( (' '|'\\t'|'\\r'|'\\n'))+
            {
            // grammar/antlr_3/bc.g:97:5: ( (' '|'\\t'|'\\r'|'\\n'))+
            int cnt5=0;
            loop5:
            do {
                int alt5=2;
                int LA5_0 = input.LA(1);
                if ( ((LA5_0>='\t' && LA5_0<='\n')||LA5_0=='\r'||LA5_0==' ') ) {
                    alt5=1;
                }


                switch (alt5) {
            	case 1 :
            	    // grammar/antlr_3/bc.g:97:7: (' '|'\\t'|'\\r'|'\\n')
            	    {
            	    if ( (input.LA(1)>='\t' && input.LA(1)<='\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse =
            	            new MismatchedSetException(null,input);
            	        recover(mse);    throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt5 >= 1 ) break loop5;
                        EarlyExitException eee =
                            new EarlyExitException(5, input);
                        throw eee;
                }
                cnt5++;
            } while (true);


                  channel = 99;       // send into nirwana 
                

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end WS

    // $ANTLR start NEWLINE
    public void mNEWLINE() throws RecognitionException {
        try {
            ruleNestingLevel++;
            // grammar/antlr_3/bc.g:106:5: ( ( '\\r' )? ( '\\n' )+ )
            // grammar/antlr_3/bc.g:106:5: ( '\\r' )? ( '\\n' )+
            {
            // grammar/antlr_3/bc.g:106:5: ( '\\r' )?
            int alt6=2;
            int LA6_0 = input.LA(1);
            if ( (LA6_0=='\r') ) {
                alt6=1;
            }
            switch (alt6) {
                case 1 :
                    // grammar/antlr_3/bc.g:106:6: '\\r'
                    {
                    match('\r'); 

                    }
                    break;

            }

            // grammar/antlr_3/bc.g:106:13: ( '\\n' )+
            int cnt7=0;
            loop7:
            do {
                int alt7=2;
                int LA7_0 = input.LA(1);
                if ( (LA7_0=='\n') ) {
                    alt7=1;
                }


                switch (alt7) {
            	case 1 :
            	    // grammar/antlr_3/bc.g:106:13: '\\n'
            	    {
            	    match('\n'); 

            	    }
            	    break;

            	default :
            	    if ( cnt7 >= 1 ) break loop7;
                        EarlyExitException eee =
                            new EarlyExitException(7, input);
                        throw eee;
                }
                cnt7++;
            } while (true);


            }

        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end NEWLINE

    // $ANTLR start STRING
    public void mSTRING() throws RecognitionException {
        try {
            ruleNestingLevel++;
            int type = STRING;
            int start = getCharIndex();
            int line = getLine();
            int charPosition = getCharPositionInLine();
            int channel = Token.DEFAULT_CHANNEL;
            // grammar/antlr_3/bc.g:112:5: ( '\\\"' (~ '\\\"' )* '\\\"' )
            // grammar/antlr_3/bc.g:112:5: '\\\"' (~ '\\\"' )* '\\\"'
            {
            match('\"'); 
            // grammar/antlr_3/bc.g:112:10: (~ '\\\"' )*
            loop8:
            do {
                int alt8=2;
                int LA8_0 = input.LA(1);
                if ( ((LA8_0>='\u0000' && LA8_0<='!')||(LA8_0>='#' && LA8_0<='\uFFFE')) ) {
                    alt8=1;
                }


                switch (alt8) {
            	case 1 :
            	    // grammar/antlr_3/bc.g:112:12: ~ '\\\"'
            	    {
            	    if ( (input.LA(1)>='\u0000' && input.LA(1)<='!')||(input.LA(1)>='#' && input.LA(1)<='\uFFFE') ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse =
            	            new MismatchedSetException(null,input);
            	        recover(mse);    throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop8;
                }
            } while (true);

            match('\"'); 

            }



                    if ( token==null && ruleNestingLevel==1 ) {
                        emit(type,line,charPosition,channel,start,getCharIndex()-1);
                    }

                        }
        finally {
            ruleNestingLevel--;
        }
    }
    // $ANTLR end STRING

    public void mTokens() throws RecognitionException {
        // grammar/antlr_3/bc.g:1:10: ( T13 | T14 | T15 | T16 | NUMBER | MINUS | PLUS | ML_COMMENT | WS | STRING )
        int alt9=10;
        switch ( input.LA(1) ) {
        case ';':
            alt9=1;
            break;
        case '(':
            alt9=2;
            break;
        case ')':
            alt9=3;
            break;
        case 'q':
            alt9=4;
            break;
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            alt9=5;
            break;
        case '-':
            alt9=6;
            break;
        case '+':
            alt9=7;
            break;
        case '/':
            alt9=8;
            break;
        case '\t':
        case '\n':
        case '\r':
        case ' ':
            alt9=9;
            break;
        case '\"':
            alt9=10;
            break;
        default:
            NoViableAltException nvae =
                new NoViableAltException("1:1: Tokens : ( T13 | T14 | T15 | T16 | NUMBER | MINUS | PLUS | ML_COMMENT | WS | STRING );", 9, 0, input);

            throw nvae;
        }

        switch (alt9) {
            case 1 :
                // grammar/antlr_3/bc.g:1:10: T13
                {
                mT13(); 

                }
                break;
            case 2 :
                // grammar/antlr_3/bc.g:1:14: T14
                {
                mT14(); 

                }
                break;
            case 3 :
                // grammar/antlr_3/bc.g:1:18: T15
                {
                mT15(); 

                }
                break;
            case 4 :
                // grammar/antlr_3/bc.g:1:22: T16
                {
                mT16(); 

                }
                break;
            case 5 :
                // grammar/antlr_3/bc.g:1:26: NUMBER
                {
                mNUMBER(); 

                }
                break;
            case 6 :
                // grammar/antlr_3/bc.g:1:33: MINUS
                {
                mMINUS(); 

                }
                break;
            case 7 :
                // grammar/antlr_3/bc.g:1:39: PLUS
                {
                mPLUS(); 

                }
                break;
            case 8 :
                // grammar/antlr_3/bc.g:1:44: ML_COMMENT
                {
                mML_COMMENT(); 

                }
                break;
            case 9 :
                // grammar/antlr_3/bc.g:1:55: WS
                {
                mWS(); 

                }
                break;
            case 10 :
                // grammar/antlr_3/bc.g:1:58: STRING
                {
                mSTRING(); 

                }
                break;

        }

    }


 

}