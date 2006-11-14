<?xml version='1.0'?>
<xsl:stylesheet 
  xmlns:past="http://www.parrotcode.org/PAST-0.1"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
  version="1.0"
>
<!--

$Id$

This transformation takes an abstract syntax tree as generated 
by phc_xml_to_past_xml.xsl. It generates a script in PIR that creates
a Patrick Michaud PAST and runs the PAST.

-->
<xsl:output method='text' />

<xsl:template match="/" >

# Do not edit this file.                                          
# This file has been generated by past_xml_to_past_pir.xsl
                                                                  
.sub plumhead :main                                                     

  load_bytecode 'PAST-pm.pbc'                                        
  load_bytecode 'MIME/Base64.pbc'              
  load_bytecode 'dumper.pbc'
                                                                  
  # phc encodes most but not all strings in base64
  .local pmc decode_base64
  decode_base64 = get_global [ "MIME"; "Base64" ], 'decode_base64'
    
  # The root node of PAST.
  .local pmc past
  .local pmc past_node_<xsl:value-of select="generate-id(.)" />                                                  
  past_node_<xsl:value-of select="generate-id(.)" />  = new 'PAST::Block'
  past_node_<xsl:value-of select="generate-id(.)" />.init('name' => 'anon')

  <xsl:apply-templates />

  '_dumper'(past_node_<xsl:value-of select="generate-id(.)" />, 'past')

  .local pmc compiled
  compiled = past_node_<xsl:value-of select="generate-id(.)" />.'compile'( 'target' => 'post' )
  '_dumper'(compiled, 'compiled')
  compiled()

                                                                  
.end                                                              
                                                                  
# helpers

.sub _slurp_file                                                  
  .param string filename                                          
                                                                  
  .local pmc filehandle                                             
  .local string content                                             
  filehandle = open filename, '&lt;'                                 
  unless filehandle goto ERR_NO_FILE                              
  content = read filehandle, 65535                                
  close filehandle                                                
                                                                  
  .return ( content )                                             
                                                                  
  ERR_NO_FILE:                                                    
    print 'Unable to open file: '                                 
    say filename                                                  
    end                                                           
                                                                  
.end                                                              
                                                                  
</xsl:template>

<xsl:template match="past:Stmts | past:Op | past:Val | past:Var" >

  # start of generic node
  .local pmc past_node_<xsl:value-of select="generate-id(.)" />                                                  
  past_node_<xsl:value-of select="generate-id(.)" /> = new '<xsl:choose>
    <xsl:when test="name() = 'past:Exp'"   >PAST::Exp</xsl:when>
    <xsl:when test="name() = 'past:Op'"    >PAST::Op</xsl:when>
    <xsl:when test="name() = 'past:Stmt'"  >PAST::Stmt</xsl:when>
    <xsl:when test="name() = 'past:Stmts'" >PAST::Stmts</xsl:when>
    <xsl:when test="name() = 'past:Var'"   >PAST::Var</xsl:when>
                                                            </xsl:choose>'
  <xsl:apply-templates select="@*"/>
  <xsl:apply-templates />
  past_node_<xsl:value-of select="generate-id(..)" />.'push'( past_node_<xsl:value-of select="generate-id(.)" /> )      
  null past_node_<xsl:value-of select="generate-id(.)" />
  # end of generic node

</xsl:template>

<xsl:template match="past:Val">

  # start of past:Val
  <xsl:choose>
    <xsl:when test="@valtype = 'strq'" >
      .local string val_<xsl:value-of select="generate-id(.)" />
      <xsl:choose>
        <xsl:when test="@encoding = 'base64'" >
          val_<xsl:value-of select="generate-id(.)" /> = decode_base64( "<xsl:value-of select="." />" )
          val_<xsl:value-of select="generate-id(.)" /> = escape val_<xsl:value-of select="generate-id(.)" />
        </xsl:when>
        <xsl:otherwise>
          val_<xsl:value-of select="generate-id(.)" /> = "<xsl:value-of select="." />"
        </xsl:otherwise>
      </xsl:choose>
    </xsl:when>
    <xsl:when test="@valtype = 'int'" >
      .local int val_<xsl:value-of select="generate-id(.)" />
      val_<xsl:value-of select="generate-id(.)" /> = <xsl:value-of select="." />
    </xsl:when>
    <xsl:when test="@valtype = 'num'" >
      .local num val_<xsl:value-of select="generate-id(.)" />
      val_<xsl:value-of select="generate-id(.)" /> = <xsl:value-of select="." />
    </xsl:when>
  </xsl:choose>

  .local pmc past_node_<xsl:value-of select="generate-id(.)" />
  past_node_<xsl:value-of select="generate-id(.)" /> = new 'PAST::Val'                             
  <xsl:apply-templates select="@*"/>
  past_node_<xsl:value-of select="generate-id(..)" />.'push'( past_node_<xsl:value-of select="generate-id(.)" /> )      
  # end of past:Val

</xsl:template>

<!-- handle attributes -->
<xsl:template match="@*">
  past_node_<xsl:value-of select="generate-id(..)" />.'attr'( '<xsl:value-of select="name()" />', '<xsl:value-of select="." />', 1 )                              
</xsl:template>
<xsl:template match="@encoding">
   <xsl:comment>The attribute encoding is handled in PIR generation</xsl:comment>
</xsl:template>

</xsl:stylesheet>
