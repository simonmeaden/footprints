<!DOCTYPE html>






<!-- paulirish.com/2008/conditional-stylesheets-vs-css-hacks-answer-neither/ -->
<!--[if IE 8]> <html class="no-js lt-ie9" lang="en"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="en"> <!--<![endif]-->

<head>
    <title>
    SPI_TFT_ILI9341 - a mercurial repository
 | mbed</title>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=9; IE=8; IE=7; IE=EDGE" />
    <!-- Set the viewport width to device width for mobile -->
    <meta name="viewport" content="user-scalable=yes,width=device-width,initial-scale=0.9" />

    

    <!-- Included CSS Files -->
    <link type="text/css" href="/static/css/app.css" rel="stylesheet" /><link type="text/css" href="/static/css/mbed.css" rel="stylesheet" /><link type="text/css" href="/static/css/questions.css" rel="stylesheet" /><link rel="stylesheet" href="/static/css/responsive-tables.css" /><link rel="stylesheet" href="/static/webfonts/ss-standard.css" /><link rel="stylesheet" href="/static/css/general_foundicons.css" /><link rel="stylesheet" href="/static/css/social_foundicons.css" /><link rel="stylesheet" href="/static/css/import-button.css" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">
    <link rel="stylesheet" type="text/css" href="https://fonts.googleapis.com/css?family=Open+Sans:400italic,400,600italic,600,700italic,700,800italic,800">

    <script src="/static/js/foundation/modernizr.foundation.js"></script>
<script src="/static/js/foundation/jquery.js"></script>
<script type="text/javascript" src="/static/js/date.js"></script>
<script type="text/javascript" src="/static/js/mbedcom.js"></script>
<script type="text/javascript" src="/static/js/import-button.js"></script>
<script type="text/javascript" src="/static/js/jquery.timeago.js"></script>
<script type="text/javascript" src="/static/js/jquery.cycle.all.latest.js"></script>
<script type="text/javascript" src="/static/js/json2.js"></script>
<script src="/static/js/foundation/jquery.event.move.js"></script>
<script src="/static/js/foundation/jquery.event.swipe.js"></script>
<script src="/static/js/foundation/jquery.foundation.alerts.js"></script>
<script src="/static/js/foundation/jquery.foundation.buttons.js"></script>
<script src="/static/js/foundation/jquery.foundation.forms.js"></script>
<script src="/static/js/foundation/jquery.foundation.navigation.js"></script>
<script src="/static/js/foundation/jquery.foundation.tabs.js"></script>
<script src="/static/js/foundation/jquery.foundation.reveal.js"></script>
<script src="/static/js/foundation/jquery.foundation.topbar.js"></script>
<script src="/static/js/foundation/jquery.placeholder.js"></script>
<script src="/static/js/foundation/responsive-tables.js"></script>
<script src="/static/js/jquery.smooth-scroll.min.js"></script>
<script src="/static/webfonts/ss-standard.js"></script>
<script src="/static/webfonts/ss-social.js"></script>
<script src="/static/js/foundation/app.js"></script>
<script src="/static/js/clipboard.min.js"></script>

    
    
<!--[if IE]><script type="text/javascript" src="/static/js/excanvas.js"></script><![endif]-->
  <link rel="stylesheet" type="text/css" href="/static/css/hgstyle.css" />

</head>

<body>
    
<style>
@charset "UTF-8";
/* CSS Document */

body { font-family: "Open Sans", Arial, sans-serif; }

.common-top-bar .dropdown, .sub-bar .dropdown { border: none; box-shadow: 0 5px 3px 1px rgba(0, 0, 0, 0.3); top: 100%; left: 0px!important; }

/* main nav */
.common-top-bar { padding: 0px 0.5em; min-height:60px;}
.common-top-bar .columns { padding-left: 0; }
.common-top-bar { background: #fff; }
.common-top-bar ul li { border-top: 5px solid #fff;}
.common-top-bar ul li a { font-size: 0.9em; color: #7a7a7a; font-weight: 400; margin: 0.6rem 0; padding: 0.1rem 0.8rem; }
.common-top-bar ul li.logo a { padding-left: 0.1rem;}
.common-top-bar .menu li a img.logo { min-width: 50px!important; height: 24px;
    width: 168px;
    margin-bottom: 5px;}
.common-top-bar .search .button { border:none; background: none; border-color: none; color: #7a7a7a; position: absolute; top: 2px;  right: 0; }
.common-top-bar .search form { position: relative; padding: 0 0; width: 100%!important;}
.common-top-bar .search form, .common-top-bar .search form input { width: 100%; max-width: 100%; height:40px;}
.common-top-bar input {  margin: 10px 0.3em 10px 0;  max-width: auto; top: 0;}
.common-top-bar ul li.selected { border-top: 5px solid #fff; }
.common-top-bar ul li.dev.selected { border-top: 5px solid #00C3DC; }
.common-top-bar ul li.partners.selected { border-top: 5px solid #8A6EAF; }
.menu > li {
    display: table-cell;
}
.menu{padding-left:0px;}
.common-top-bar ul li.selected a:link, .off-canvas-wrap{background:white;}
/* sub nav */
.sub-bar { background-color: #0a7084; }
.sub-bar a { color: #fff; font-size: 0.9em;}
.has-dropdown .dropdown a { color: #7a7a7a; }
.sub-bar .row { margin: 0 auto; }
.sub-bar.mbedcom .row { max-width: 62.5rem; }
.sub-bar.dev .row { max-width: 100%;  width: 1200px; }
.sub-bar.dev { display: none; background: #128CAB; }
.sub-bar.partners { display: none; background: #6A4E93; }
.sub-bar.partners .row {/* max-width: 62.5rem; */}
.sub-bar ul li { padding: 0.8rem 0; }
.sub-bar ul li a { padding: 0.2em 1em 0.2em 1em; }
.sub-bar .user-links { padding: 0.4rem 0; }
.sub-bar .user-links a { padding: 0.6em 1em; background: rgba(0, 195, 220, 1); font-weight: 600; margin-right: 1rem; margin-left: 1rem;}
.sub-bar .user-links a:hover { background: rgba(0, 195, 220, 0.5); }
.sub-bar .dropdown { padding: 0.3rem;}
.sub-bar .dropdown li { padding: 0.2rem 0; }

.language .dropdown a { border: none; }
.menu .active a { background: #fff; }
ul.menu {
    margin-left: 0;
}
.dropdown.menu li.is-dropdown-submenu-parent a::after { border: #fff; }

ul.menu li.has-dropdown ul.dropdown li a {
    background-image: none;
    display: block;
    line-height: 1.4em;
    padding: 5px 10px;
}
ul.menu li a .fa { margin-left: 8px; }
iframe { height: 100%; }

::-webkit-input-placeholder { /* WebKit, Blink, Edge */
    color:    rgba(20, 20, 20, 0.4);
}
:-moz-placeholder { /* Mozilla Firefox 4 to 18 */
   color:    rgba(20, 20, 20, 0.4);
   opacity:  1;
}
::-moz-placeholder { /* Mozilla Firefox 19+ */
   color:    rgba(20, 20, 20, 0.4);
   opacity:  1;
}
:-ms-input-placeholder { /* Internet Explorer 10-11 */
   color:    rgba(20, 20, 20, 0.4);
}

/* Medium only */
@media screen and (min-width: 40em) and (max-width: 63.9375em) {

   .sub-bar.dev ul li a { padding-left: 0.3rem; padding-right: 0.3rem; }
   .sub-bar.dev ul li.user-links a { padding-left: 1rem; padding-right: 1rem; }
   .sub-bar.dev ul li.home a { background: blue1; }
}


/* Small only */
@media screen and (max-width: 39.9375em) {
   /* main nav */
   .common-common-top-bar .nav, .common-common-top-bar .search { padding-left: 0; padding-right: 0;}
   .common-common-top-bar ul li.logo a { padding-left: 0; }

   .nav.columns{height:50px;}

   .common-top-bar{height:115px;}
   /* sub nav */
   .sub-bar ul li { padding: 0.8rem 0; }
   .sub-bar ul li a.menutrigger { margin-left: -0.8em;  }
   .sub-bar ul li.home a { padding: 0.2em 0.8em 0.2em 0.3em; border-right: 2px dotted rgba(255, 255, 255, 0.3);}
   .sub-bar ul li a { padding: 0.2em 0.5em 0.2em 0.5em; }
   .sub-bar ul li.is-accordion-submenu-parent a { padding-left: 2.1rem;}
   .sub-bar ul li.is-accordion-submenu-parent a::after { border-color: #fff transparent transparent; left: 0.8rem; top: 55%; }
   .sub-bar ul.sub-menu .menu.vertical.nested { background: red; }
   .sub-bar ul.sub-menu { margin-top: 0.5rem;}
   .sub-bar ul.sub-menu li { padding-top: 0.5rem; padding-bottom: 0.5rem; }
   .sub-bar ul.sub-menu li a { font-weight: 600; }
   .sub-bar ul.sub-menu li ul a { font-weight: 300; }
   .sub-bar ul.sub-menu li ul li { padding-top: 0.3rem; padding-bottom: 0.3rem; }
   .sub-bar .language .dropdown { left: inherit!important; right: 0px!important; }
 }

</style>
<div class="common-top-bar top-bar">
    <div class="nav small-12 medium-9 columns">
        <ul class="menu" data-dropdown-menu="t822t7-dropdown-menu" role="menubar">
            <li class="mbedcom logo " role="menuitem">
                <a title="back to mbed home" href="https://mbed.com"  tabindex="0">
                    <img src="https://www.mbed.com/static/img/ARMmbedLogo.svg" alt="" class="logo">
                </a>
            </li>
            <li class="dev selected" role="menuitem">
                <a href="https://developer.mbed.org" >
                    Developer <span class="hide-for-small-only">Resources</span>
                </a>
            </li>
            <li class="partners " role="menuitem">
                <a href="https://partners.mbed.com" >Partners</a>
            </li>
            <li class="cloud" role="menuitem">
                <a href="https://cloud.mbed.com" >Cloud</a>
            </li>
        </ul>
    </div>
    <div class="search small-12 medium-3 medium three columns">
        <form class="search float-right" action="https://developer.mbed.org/search/" method="GET">
            <input type="search" name="q" placeholder="Search mbed...">
            <button type="submit button" class="button"><i class="general fa fa-search"></i></button>
        </form>
    </div>
</div>

    <div class="nav-wrapper hide-on-print">
        <div class="row">
            <div class="twelve columns navigation">
            

                <ul class="nav-bar menu-list" id="nav">

                    <li class="hasdropdown not-click">
                        <a href="#">
                            Hardware
                        </a>
                        <ul class="dropdown no-bullet">
                            <li><a href="/platforms">Boards</a></li>
                            <li><a href="/components/">Components</a></li>
                        </ul>
                    </li>
                    <li class="hasdropdown not-click">
                        <a href="#">
                            Documentation
                        </a>
                        <ul class="dropdown no-bullet">
                            <li><a href="https://docs.mbed.com/">Documentation</a></li>
                            <li><a href="/cookbook/">Cookbook</a></li>
                        </ul>
                    </li>
                    <li><a href="/code/">Code</a></li>
                    <li><a href="/questions/">Questions</a></li>
                    <li><a href="/forum/">Forum</a></li>
                    <li class="navSpacer">|</li>
                    
                    <li><a href="/account/login/?next=/users/dreschpe/code/SPI_TFT_ILI9341/file/b2b3e5430f81/SPI_TFT_ILI9341.cpp">Log In/Signup</a></li>
                     
                    <li class="user-links"><a href="/compiler/" target="_blank">Compiler</a></li>

                </ul>
            
            </div>
        </div>
    </div>

    <div class="blue">
        <div class="row" id="top">
            <div class="six columns">
                <div class="breadcrumbs">
                    
    
    <a href="/activity/">Users</a> &raquo; <a href="/users/dreschpe/">dreschpe</a>
    
    
 
        &raquo; <a href="/users/dreschpe/code/">Code</a>

        
        &raquo; <a href="/users/dreschpe/code/SPI_TFT_ILI9341/">SPI_TFT_ILI9341</a>


                </div>
            </div>
            <div class="six columns header search-block">
                
                
            </div>
        </div><!-- end of #top -->

        
    </div>

    
<div class="row">
    <div class="nine columns main-content" id="mbed-content">
        

        







<div class="content-actions"></div>




<div style="font-size: 1.6em; padding-bottom: 4px;">
    
        <a href="/users/dreschpe/">
            
                <img src="/media/cache/profiles/fe04e05fbe48920b8ba90bea2ddfe60b.50x50_q85.jpg" width="39" height="50" >

            Peter Drescher
        </a> 
    
    / <a style="font-weight: bold;" href="/users/dreschpe/code/SPI_TFT_ILI9341/">
        
            <i title="This repository is a library" class="fa icon_library_2" aria-hidden="true"></i>
        

        SPI_TFT_ILI9341</a>

    
</div>



    <br/>
    <p>Lib for the new LCD Display with ILI9341 controller</p>





    <p>
    <b>  
        
            <a href="/users/dreschpe/code/SPI_TFT_ILI9341/dependents">
                <i class="fa fa-sitemap" aria-hidden="true"></i> Dependents:
            </a> &nbsp;
        
    </b>

    
        <a href="/users/dreschpe/code/TFT_Test_ILI9341/">
            
                <i title="This repository is a program" class="fa icon_program_2" aria-hidden="true"></i>
            
            TFT_Test_ILI9341
        </a>
    
        <a href="/users/Vekotin/code/touch_piirto/">
            
                <i title="This repository is a program" class="fa icon_program_2" aria-hidden="true"></i>
            
            touch_piirto
        </a>
    
        <a href="/users/dreschpe/code/TFT_banggood/">
            
                <i title="This repository is a program" class="fa icon_program_2" aria-hidden="true"></i>
            
            TFT_banggood
        </a>
    
        <a href="/users/you_sun/code/TFT_Test_ILI9341-a-fish/">
            
                <i title="This repository is a program" class="fa icon_program_2" aria-hidden="true"></i>
            
            TFT_Test_ILI9341-a-fish
        </a>
    

    
        <small>
            
                <a href="/users/dreschpe/code/SPI_TFT_ILI9341/dependents">
                    ... more
                </a>
            
        </small>
    
    </p>







   

<div class="page-header">
        <ul id="tabmenu">


            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/" >
              Home</a></li>


            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/shortlog"  >
              History</a></li>


            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/graph"  >
             Graph</a></li>


            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/docs/"  >
              API Documentation</a></li>


            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/wiki/"  >
              Wiki</a></li>


    
                <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/issues/"  >
                  Issues</a></li>
    


    
                <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/pull-requests/"  >
                  Pull Requests</a></li>
    





        </ul>
    </div>



<p>Lib for 320*240 Pixel Color LCD with ILI9341 controller. Based on MI0283QT-9 datasheet.
The lib is based on the <a href="http://mbed.org/cookbook/SPI-driven-QVGA-TFT">http://mbed.org/cookbook/SPI-driven-QVGA-TFT</a> code for the older LCD board.</p>
<p>The lib is using the 4 line serial data interface. The IM pins have to be set to 1110 (IM3-IM0) to use this mode.
It use the SPI hardware.</p>
<p>I have started to speed up the lib with using DMA and direct SPI programming. To do this I have to split the code for the different platforms. To prevent unreadable code with a lot of #ifdef... I have create a new file. The #ifdef definition around is switching between the platforms. 
I will add the other Nucleo platforms. If you want to support others  - see ..._NUCLEO.cpp  , port and send me the code to add. </p>
<h2>Display 1</h2>
<p>If you use the TFT Proto from MikroElektronika <a href="http://www.mikroe.com/eng/products/view/474/tft-proto-board/" rel="nofollow">http://www.mikroe.com/eng/products/view/474/tft-proto-board/</a> 
you have to connect :                 <img src="/media/uploads/dreschpe/tft_proto.png" alt="/media/uploads/dreschpe/tft_proto.png" title="/media/uploads/dreschpe/tft_proto.png" /> </p>
<table><tr><th>MBED</th><th>Display</th></tr>
<tr><td>+ 3,3V</td><td>3,3V</td></tr>
<tr><td>GND</td><td>GND</td></tr>
<tr><td>mosi</td><td>SDI</td></tr>
<tr><td>miso</td><td>SDO</td></tr>
<tr><td>sck</td><td>RS</td></tr>
<tr><td>cs</td><td>CS</td></tr>
<tr><td>reset</td><td>RST</td></tr>
<tr><td>dc</td><td>WR/SCL</td></tr>
<tr><td>GND</td><td>IM0</td></tr>
<tr><td>+3,3V</td><td>IM1 IM2 IM3</td></tr>
<tr><td>GND</td><td>DB0 - DB17</td></tr>
<tr><td>GND</td><td>RD</td></tr>
</table>
<p>The backlite LED need a resistor to limit the current. You can use two 10R resistors parallel to get 5R driven by 3.3V.</p>
<h2>Display 2</h2>
<p>Watterott is also selling a ILI9341 based QVGA TFT :
<a href="http://www.watterott.com/de/MI0283QT-2-Adapter" rel="nofollow">http://www.watterott.com/de/MI0283QT-2-Adapter</a></p>
<p>Unfortunately this adapter is set to 9 bit SPI mode via the mode pins IM0-IM3. If you want to patch this - like I have done - you have to desolder the TFT from the pcb to cut some traces. This is a flexible print. Only for people with soldering skills !
You also have to get access to pin 36 for the dc signal. Cut the GND connection.  You can use the level converter used for the LCD_LED signal. Mosfet Q1 can be driven with a  logic signal without converter. Watterott will change this in a future revision.  </p>
<p> <a href="/media/uploads/dreschpe/mi0283qt_v12_patch.pdf">/media/uploads/dreschpe/mi0283qt_v12_patch.pdf</a>    </p>
<h2>Display 3</h2>
<p>There are inexpensive displays from china. You can get them at:
<a href="http://www.banggood.com/2_2-Inch-Serial-TFT-SPI-LCD-Screen-Module-HD-240-X-320-5110-Compatible-p-912854.html" rel="nofollow">http://www.banggood.com/2_2-Inch-Serial-TFT-SPI-LCD-Screen-Module-HD-240-X-320-5110-Compatible-p-912854.html</a>
The board has also a SD card connector at the backside, but no touch.</p>
<p> <img src="/media/uploads/dreschpe/tft3_1.jpg" alt="/media/uploads/dreschpe/tft3_1.jpg" title="/media/uploads/dreschpe/tft3_1.jpg" /> 
 <img src="/media/uploads/dreschpe/tft3_2.jpg" alt="/media/uploads/dreschpe/tft3_2.jpg" title="/media/uploads/dreschpe/tft3_2.jpg" /> </p>
<p>The board can be used without modification. Connect VCC with 5V USB out. There is a voltage regulator on board.
To use the SD card simply import the SDFileSystem and connect it to the second SPI.</p>
<h2>Fonts</h2>
<p><strong>How to get nice looking fonts ?</strong></p>
<p>To print characters to a graphic screen we need a font. To code a font by paper is ok for a small lcd, but for a 320*240 pixel display we need bigger fonts. A 12*12 pixel font is readable, but a lot of work to construct.</p>
<p>Fonts can be made with the GLCD Font Creator also from <a href="http://www.mikroe.com" rel="nofollow">http://www.mikroe.com</a> .</p>
<p>With this program you can load a window font and convert it into a c-array.
To use this Font with my lib you have to add 4 parameter at the beginning of the font array. 
 - the number of byte / char                                               
 - the vertial size in pixel                                               
 - the horizontal size in pixel                                            
 - the number of byte per vertical line (it is vertical size / 8 )                                    
You also have to change the array to char[].
After that you can switch between different fonts with set_font(unsigned char* font);
The horizontal size of each character is also stored in the font. It look better if you use bigger fonts or italic. The letter M is wider than a l. </p>
<p>Here are some Fonts from me :
<a href="http://mbed.org/users/dreschpe/code/TFT_fonts/">http://mbed.org/users/dreschpe/code/TFT_fonts/</a></p>
<p>The small made for the mbed lab board :
<a href="http://mbed.org/users/dreschpe/code/LCD_fonts/">http://mbed.org/users/dreschpe/code/LCD_fonts/</a></p>
<p>And from Peter Holzleitner :
<a href="http://mbed.org/users/pholzleitner/code/SourceCodePro31-SB/">http://mbed.org/users/pholzleitner/code/SourceCodePro31-SB/</a></p>
<p><strong>Text commands :</strong></p>
<p>You can use the claim() function to redirect the output to stdout or stderr to the TFT.
After claim(stdout) you can simply use the printf function to print to the TFT.</p>
<ul><li>locate(x,y); function is used to setup the cursor position. x,y are the pixel position. This was changed from row,column in older lib !
</li></ul>
<p>There are two parameter to setup the color of the text : </p>
<ul><li>background(color);
</li><li>foreground(color);    All color are 16bit: R5 G6 B5.
</li></ul>
<ul><li>set_orientation(); This command select one of the 4 directions to use the display. This command is also working on the graphical commands.
</li></ul>
<h2>Graphics</h2>
<p><strong>Graphic commands :</strong></p>
<ul><li>cls(); Fill the screen with background color
</li><li>pixel(x,y,color); set a single pixel at x,y with color
</li><li>line(x0,y0,x1,y1,color); draw a line from x0,y0 to x1,y1 with color
</li><li>rect(x0,y0,x1,y1,color); draw a rectangle x0,y0 to x1,y1  with color 
</li><li>fillrect(x0,y0,x1,y1,color); draw a filled rectangle
</li><li>circle( x0,y0,radius ,color); draw a circle around x0,y0 with radius 
</li><li>fillcircle(x0,y0,radius ,color); draw a filled circle around x0,y0 with radius
</li><li>Bitmap(x0,y0,w,h,*bitmap); paint a bitmap with width w and high h starting at x0,y0 (upper left corner)
</li><li>BMP_16(x0,y0,*bmp); paint a bmp file out of the internal drive or a SD-card
</li></ul>
<h3>How to transfer a grafic to the mbed ?</h3>
<p><strong>The hard way - but fast to load :</strong></p>
<p>Load from mbed flash. It consume a lot of flash memory. To construct a bitmap array we can use gimp. <a href="http://www.gimp.org/" rel="nofollow">http://www.gimp.org/</a> Load a image (edit and resize) and export it as BMP. You have to select the option 16 bit R5 G6 B5 ! </p>
<p>To convert this file into a c-array you can use the hex-editor winhex. (<a href="http://www.x-ways.net/winhex/index-m.html" rel="nofollow">http://www.x-ways.net/winhex/index-m.html</a>) The eval version can handle the small files. 
We don`t need the bmp header. Mark the data starting at offset 0x46 to the end of file. 
Use "edit -&gt; copy block -&gt; C Source" to export this data as C array. Paste the data into a C file into the mbed compiler. 
The editor will generate a array of char[]. To use 16 bit DMA on this we have to put a <code>__align(2)</code> in front of the definition.
To put it into Flash we change it to static const unsigned char bmp[]{...}</p>
<div class="flashbox fcode"><h4 class="ftitle"> </h4><pre class="mbed-code" offset="0">__align(2)
static const unsigned char bmp[]{
      0xCB, 0x5A, 0x5C, 0xE7,....

};
</pre></div><p><strong>The easy way - but slower to load:</strong></p>
<p>With the BMP_16 command we can load a picture out of the internal drive or a SD-card to the display.</p>
<ul><li>BMP_16(x0,y0,"/local/test.bmp"); paint test.bmp out of the internal drive to x0, y0
</li><li>BMP_16(x0,y0,"/sd/test.bmp");     paint test.bmp out of a external SD-card to x0, y0
</li></ul>
<p>simply copy test.bmp to the mbed usb drive or the SD-card. The bmp has to be saved with the options 16 bit R5 G6 B5 ! You can use the program gimp to convert pictures into the 16 bit bmp format.</p>
<h2>sample code</h2>
<p><a href="http://mbed.org/users/dreschpe/code/TFT_Test_ILI9341/">http://mbed.org/users/dreschpe/code/TFT_Test_ILI9341/</a></p>
<div class="flashbox fcode"><h4 class="ftitle"> </h4><pre class="mbed-code" offset="0">
// example to test the TFT Display
// Thanks to the GraphicsDisplay and TextDisplay classes
// test2.bmp has to be on the mbed file system

#include "stdio.h"
#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial12x12.h"
#include "Arial24x23.h"
#include "Arial28x28.h"
#include "font_big.h"

extern unsigned char p1[];  // the mbed logo

DigitalOut LCD_LED(p21); // the Watterott display has a backlight switch
DigitalOut CS_Touch(p15); // disable the touch controller on the Watterott display

// the TFT is connected to SPI pin 5-7
SPI_TFT_ILI9341 TFT(p5, p6, p7, p8, p9, p10,"TFT"); // mosi, miso, sclk, cs, reset, dc

int main()
{
    int i;
    LCD_LED = 1;  // backlight on
    CS_Touch = 1; 
   
    TFT.claim(stdout);      // send stdout to the TFT display
    //TFT.claim(stderr);      // send stderr to the TFT display
    TFT.set_orientation(1);
    TFT.background(Black);    // set background to black
    TFT.foreground(White);    // set chars to white
    TFT.cls();                // clear the screen

    //first show the 4 directions
    TFT.set_orientation(0);
    TFT.background(Black);
    TFT.cls();

    TFT.set_font((unsigned char*) Arial12x12);
    TFT.locate(0,0);
    printf("  Hello Mbed 0");

    TFT.set_orientation(1);
    TFT.locate(0,0);
    printf("  Hello Mbed 1");
    TFT.set_orientation(2);
    TFT.locate(0,0);
    printf("  Hello Mbed 2");
    TFT.set_orientation(3);
    TFT.locate(0,0);
    printf("  Hello Mbed 3");
    TFT.set_orientation(1);
    TFT.set_font((unsigned char*) Arial24x23);
    TFT.locate(50,100);
    TFT.printf("TFT orientation");
</pre></div><p> <img src="/media/uploads/dreschpe/orient.jpg" alt="/media/uploads/dreschpe/orient.jpg" title="/media/uploads/dreschpe/orient.jpg" /> </p>
<div class="flashbox fcode"><h4 class="ftitle"> </h4><pre class="mbed-code" offset="0">// draw some graphics
    TFT.cls();
    TFT.set_font((unsigned char*) Arial24x23);
    TFT.locate(100,100);
    TFT.printf("Graphic");

    TFT.line(0,0,100,0,Green);
    TFT.line(0,0,0,200,Green);
    TFT.line(0,0,100,200,Green);

    TFT.rect(100,50,150,100,Red);
    TFT.fillrect(180,25,220,70,Blue);

    TFT.circle(80,150,33,White);
    TFT.fillcircle(160,190,20,Yellow);

    double s;

    for (i=0; i&lt;320; i++) {
        s =20 * sin((long double) i / 10 );
        TFT.pixel(i,100 + (int)s ,Red);
    }
</pre></div><p> <img src="/media/uploads/dreschpe/grafik.jpg" alt="/media/uploads/dreschpe/grafik.jpg" title="/media/uploads/dreschpe/grafik.jpg" /> </p>
<div class="flashbox fcode"><h4 class="ftitle"> </h4><pre class="mbed-code" offset="0">   // bigger text
    TFT.foreground(White);
    TFT.background(Blue);
    TFT.cls();
    TFT.set_font((unsigned char*) Arial24x23);
    TFT.locate(0,0);
    TFT.printf("Different Fonts :");

    TFT.set_font((unsigned char*) Neu42x35);
    TFT.locate(0,30);
    TFT.printf("Hello Mbed 1");
    TFT.set_font((unsigned char*) Arial24x23);
    TFT.locate(20,80);
    TFT.printf("Hello Mbed 2");
    TFT.set_font((unsigned char*) Arial12x12);
    TFT.locate(35,120);
    TFT.printf("Hello Mbed 3");

</pre></div><p> <img src="/media/uploads/dreschpe/fonts2.jpg" alt="/media/uploads/dreschpe/fonts2.jpg" title="/media/uploads/dreschpe/fonts2.jpg" /> </p>
<div class="flashbox fcode"><h4 class="ftitle"> </h4><pre class="mbed-code" offset="0">    // mbed logo from flash
    // defined in graphics.c
    //__align(4)
    //unsigned char p1[18920] = {
    //0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, ....
    // 
    TFT.background(Black);
    TFT.cls();

    TFT.locate(10,10);
    TFT.printf("Graphic from Flash");

    TFT.Bitmap(90,90,172,55,p1);

</pre></div><p> <img src="/media/uploads/dreschpe/mbed.jpg" alt="/media/uploads/dreschpe/mbed.jpg" title="/media/uploads/dreschpe/mbed.jpg" /> </p>
<div class="flashbox fcode"><h4 class="ftitle"> </h4><pre class="mbed-code" offset="0">  
  #include "SDFileSystem.h"
  // connect a sd-card to the second spi or use the local filesystem of the LPC   
  SDFileSystem sd(p11, p12, p13, p14, "sd"); // mosi,miso,sck,cs
  TFT.cls();
  TFT.locate(10,110);
  TFT.printf("Graphic from external SD-card");
  int err = TFT.BMP_16(1,140,"/sd/test.bmp");  // load test.bmp from external SD-card
  TFT.locate(10,120);
  if (err != 1) TFT.printf(" - Err: %d",err);

</pre></div><p> <img src="/media/uploads/dreschpe/bmp16.jpg" alt="/media/uploads/dreschpe/bmp16.jpg" title="/media/uploads/dreschpe/bmp16.jpg" /> </p>




<div id="container">
      
        <ul class="object-tools" >
            <li class="current"><a href="/users/dreschpe/code/SPI_TFT_ILI9341/file/b2b3e5430f81/SPI_TFT_ILI9341.cpp">file</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/log/b2b3e5430f81/SPI_TFT_ILI9341.cpp">revisions</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/annotate/b2b3e5430f81/SPI_TFT_ILI9341.cpp">annotate</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/diff/b2b3e5430f81/SPI_TFT_ILI9341.cpp">diff</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/raw-file/b2b3e5430f81/SPI_TFT_ILI9341.cpp">raw</a></li>
        </ul>

   <div class="module">

    <h2>SPI_TFT_ILI9341.cpp</h2>

    <dl class="overview ">
        <dt>Committer:</dt>
        <dd>dreschpe</dd>
        <dt>Date:</dt>
        <dd><abbr class="timeago" title="Wed Jun 25 16:51:27 2014 +0000">2014-06-25</abbr></dd>
        
        <dt>Revision:</dt>
        <dd><b><a class="list" href="/users/dreschpe/code/SPI_TFT_ILI9341/rev/#node|short#">13:b2b3e5430f81</a></b></dd>
        <dt>Parent: </dt><dd><a href="/users/dreschpe/code/SPI_TFT_ILI9341/file/98cc5c193ecd/SPI_TFT_ILI9341.cpp"> 12:98cc5c193ecd</a></dd>
        
    </dl>

    <div class="source">
     <h3>File content as of revision 13:b2b3e5430f81:</h3>
        <pre class="mbed-code">
/* mbed library for 240*320 pixel display TFT based on ILI9341 LCD Controller
 * Copyright (c) 2013 Peter Drescher - DC2PD
 *
 * THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
// 12.06.13 fork from SPI_TFT code because controller is different ...
// 14.07.13 Test with real display and bugfix 
// 18.10.13 Better Circle function from Michael Ammann
// 22.10.13 Fixes for Kinetis Board - 8 bit spi
// 26.01.14 Change interface for BMP_16 to also use SD-cards
// 23.06.14 switch back to old Version - fork for L152 
// 24.06.14 Add compiler flag for optimized L152 version
// 25.06.14 Add optimized F103 version

// exclude this file for platforms with optimized version
#if defined TARGET_NUCLEO_L152RE || defined TARGET_NUCLEO_F103RB || defined TARGET_LPC1768
// this platforms are supported by special version in different source file
#else

#include &quot;SPI_TFT_ILI9341.h&quot;
#include &quot;mbed.h&quot;

#define BPP         16                  // Bits per pixel    
         
//extern Serial pc;
//extern DigitalOut xx;     // debug !!

SPI_TFT_ILI9341::SPI_TFT_ILI9341(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName dc, const char *name)
    : GraphicsDisplay(name), SPI(mosi, miso, sclk,NC), _cs(cs), _reset(reset), _dc(dc)
{
    
    orientation = 0;
    char_x = 0;
    SPI::format(8,3);                  // 8 bit spi mode 3
    SPI::frequency(10000000);          // 10 Mhz SPI clock
    tft_reset();
}

int SPI_TFT_ILI9341::width()
{
    if (orientation == 0 || orientation == 2) return 240;
    else return 320;
}


int SPI_TFT_ILI9341::height()
{
    if (orientation == 0 || orientation == 2) return 320;
    else return 240;
}


void SPI_TFT_ILI9341::set_orientation(unsigned int o)
{
    orientation = o;
    wr_cmd(0x36);                     // MEMORY_ACCESS_CONTROL
    switch (orientation) {
        case 0:
            SPI::write(0x48);
            break;
        case 1:
            SPI::write(0x28);
            break;
        case 2:
            SPI::write(0x88);
            break;
        case 3:
            SPI::write(0xE8);
            break;
    }
    _cs = 1; 
    WindowMax();
} 


// write command to tft register

void SPI_TFT_ILI9341::wr_cmd(unsigned char cmd)
{
    _dc = 0;
    _cs = 0;
    SPI::write(cmd);      // mbed lib
    _dc = 1;
}



void SPI_TFT_ILI9341::wr_dat(unsigned char dat)
{
   SPI::write(dat);      // mbed lib
}



// the ILI9341 can read 

char SPI_TFT_ILI9341::rd_byte(unsigned char cmd)
{
    char r;
    _dc = 0;
    _cs = 0;
    SPI::write(cmd);      // mbed lib
    _cs = 1;
    r = SPI::write(0xff);
    _cs = 1;    
    return(r);
}

// read 32 bit
int SPI_TFT_ILI9341::rd_32(unsigned char cmd)
{
    int d;
    char r;
    _dc = 0;
    _cs = 0;
    d = cmd;
    d = d &lt;&lt; 1;
    SPI::format(9,3);    // we have to add a dummy clock cycle
    SPI::write(d);
    SPI::format(8,3);   
    _dc = 1;
    r = SPI::write(0xff);
    d = r;
    r = SPI::write(0xff);
    d = (d &lt;&lt; 8) | r;
    r = SPI::write(0xff);
    d = (d &lt;&lt; 8) | r;
    r = SPI::write(0xff);
    d = (d &lt;&lt; 8) | r;
    _cs = 1;    
    return(d);
}

int  SPI_TFT_ILI9341::Read_ID(void){
    int r;
    r = rd_byte(0x0A);
    r = rd_byte(0x0A);
    r = rd_byte(0x0A);
    r = rd_byte(0x0A);
    return(r);
}


// Init code based on MI0283QT datasheet

void SPI_TFT_ILI9341::tft_reset()
{
    _cs = 1;                           // cs high
    _dc = 1;                           // dc high 
    _reset = 0;                        // display reset

    wait_us(50);
    _reset = 1;                       // end hardware reset
    wait_ms(5);
     
    wr_cmd(0x01);                     // SW reset  
    wait_ms(5);
    wr_cmd(0x28);                     // display off  

    /* Start Initial Sequence ----------------------------------------------------*/
     wr_cmd(0xCF);                     
     SPI::write(0x00);
     SPI::write(0x83);
     SPI::write(0x30);
     _cs = 1;
     
     wr_cmd(0xED);                     
     SPI::write(0x64);
     SPI::write(0x03);
     SPI::write(0x12);
     SPI::write(0x81);
     _cs = 1;
     
     wr_cmd(0xE8);                     
     SPI::write(0x85);
     SPI::write(0x01);
     SPI::write(0x79);
     _cs = 1;
     
     wr_cmd(0xCB);                     
     SPI::write(0x39);
     SPI::write(0x2C);
     SPI::write(0x00);
     SPI::write(0x34);
     SPI::write(0x02);
     _cs = 1;
           
     wr_cmd(0xF7);                     
     SPI::write(0x20);
     _cs = 1;
           
     wr_cmd(0xEA);                     
     SPI::write(0x00);
     SPI::write(0x00);
     _cs = 1;
     
     wr_cmd(0xC0);                     // POWER_CONTROL_1
     SPI::write(0x26);
     _cs = 1;
 
     wr_cmd(0xC1);                     // POWER_CONTROL_2
     SPI::write(0x11);
     _cs = 1;
     
     wr_cmd(0xC5);                     // VCOM_CONTROL_1
     SPI::write(0x35);
     SPI::write(0x3E);
     _cs = 1;
     
     wr_cmd(0xC7);                     // VCOM_CONTROL_2
     SPI::write(0xBE);
     _cs = 1; 
     
     wr_cmd(0x36);                     // MEMORY_ACCESS_CONTROL
     SPI::write(0x48);
     _cs = 1; 
     
     wr_cmd(0x3A);                     // COLMOD_PIXEL_FORMAT_SET
     SPI::write(0x55);                 // 16 bit pixel 
     _cs = 1;
     
     wr_cmd(0xB1);                     // Frame Rate
     SPI::write(0x00);
     SPI::write(0x1B);               
     _cs = 1;
     
     wr_cmd(0xF2);                     // Gamma Function Disable
     SPI::write(0x08);
     _cs = 1; 
     
     wr_cmd(0x26);                     
     SPI::write(0x01);                 // gamma set for curve 01/2/04/08
     _cs = 1; 
     
     wr_cmd(0xE0);                     // positive gamma correction
     SPI::write(0x1F); 
     SPI::write(0x1A); 
     SPI::write(0x18); 
     SPI::write(0x0A); 
     SPI::write(0x0F); 
     SPI::write(0x06); 
     SPI::write(0x45); 
     SPI::write(0x87); 
     SPI::write(0x32); 
     SPI::write(0x0A); 
     SPI::write(0x07); 
     SPI::write(0x02); 
     SPI::write(0x07);
     SPI::write(0x05); 
     SPI::write(0x00);
     _cs = 1;
     
     wr_cmd(0xE1);                     // negativ gamma correction
     SPI::write(0x00); 
     SPI::write(0x25); 
     SPI::write(0x27); 
     SPI::write(0x05); 
     SPI::write(0x10); 
     SPI::write(0x09); 
     SPI::write(0x3A); 
     SPI::write(0x78); 
     SPI::write(0x4D); 
     SPI::write(0x05); 
     SPI::write(0x18); 
     SPI::write(0x0D); 
     SPI::write(0x38);
     SPI::write(0x3A); 
     SPI::write(0x1F);
     _cs = 1;
     
     WindowMax ();
     
     //wr_cmd(0x34);                     // tearing effect off
     //_cs = 1;
     
     //wr_cmd(0x35);                     // tearing effect on
     //_cs = 1;
      
     wr_cmd(0xB7);                       // entry mode
     SPI::write(0x07);
     _cs = 1;
     
     wr_cmd(0xB6);                       // display function control
     SPI::write(0x0A);
     SPI::write(0x82);
     SPI::write(0x27);
     SPI::write(0x00);
     _cs = 1;
     
     wr_cmd(0x11);                     // sleep out
     _cs = 1;
     
     wait_ms(100);
     
     wr_cmd(0x29);                     // display on
     _cs = 1;
     
     wait_ms(100);
     
 }


void SPI_TFT_ILI9341::pixel(int x, int y, int color)
{
    wr_cmd(0x2A);
    SPI::write(x &gt;&gt; 8);
    SPI::write(x);
    _cs = 1;
    wr_cmd(0x2B);
    SPI::write(y &gt;&gt; 8);
    SPI::write(y);
    _cs = 1;
    wr_cmd(0x2C);  // send pixel
    #if defined TARGET_KL25Z  // 8 Bit SPI
    SPI::write(color &gt;&gt; 8);
    SPI::write(color &amp; 0xff);
    #else 
    SPI::format(16,3);                            // switch to 16 bit Mode 3
    SPI::write(color);                              // Write D0..D15
    SPI::format(8,3);
    #endif
    _cs = 1;
}


void SPI_TFT_ILI9341::window (unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
    wr_cmd(0x2A);
    SPI::write(x &gt;&gt; 8);
    SPI::write(x);
    SPI::write((x+w-1) &gt;&gt; 8);
    SPI::write(x+w-1);
    
    _cs = 1;
    wr_cmd(0x2B);
    SPI::write(y &gt;&gt; 8);
    SPI::write(y);
    SPI::write((y+h-1) &gt;&gt; 8);
    SPI::write(y+h-1);
    _cs = 1;
}


void SPI_TFT_ILI9341::WindowMax (void)
{
    window (0, 0, width(),  height());
}



void SPI_TFT_ILI9341::cls (void)
{
   // we can use the fillrect function 
   fillrect(0,0,width()-1,height()-1,_background);
}


void SPI_TFT_ILI9341::circle(int x0, int y0, int r, int color)
{

    int x = -r, y = 0, err = 2-2*r, e2;
    do {
        pixel(x0-x, y0+y,color);
        pixel(x0+x, y0+y,color);
        pixel(x0+x, y0-y,color);
        pixel(x0-x, y0-y,color);
        e2 = err;
        if (e2 &lt;= y) {
            err += ++y*2+1;
            if (-x == y &amp;&amp; e2 &lt;= x) e2 = 0;
        }
        if (e2 &gt; x) err += ++x*2+1;
    } while (x &lt;= 0);

}

void SPI_TFT_ILI9341::fillcircle(int x0, int y0, int r, int color)
{
    int x = -r, y = 0, err = 2-2*r, e2;
    do {
        vline(x0-x, y0-y, y0+y, color);
        vline(x0+x, y0-y, y0+y, color);
        e2 = err;
        if (e2 &lt;= y) {
            err += ++y*2+1;
            if (-x == y &amp;&amp; e2 &lt;= x) e2 = 0;
        }
        if (e2 &gt; x) err += ++x*2+1;
    } while (x &lt;= 0);
}


void SPI_TFT_ILI9341::hline(int x0, int x1, int y, int color)
{
    int w;
    w = x1 - x0 + 1;
    window(x0,y,w,1);
    wr_cmd(0x2C);  // send pixel
    #if defined TARGET_KL25Z  // 8 Bit SPI
    int j;
    for (j=0; j&lt;w; j++) {
        SPI::write(color &gt;&gt; 8);
        SPI::write(color &amp; 0xff);
    } 
    #else 
    SPI::format(16,3);                            // switch to 16 bit Mode 3
    int j;
    for (j=0; j&lt;w; j++) {
        SPI::write(color);
    }
    SPI::format(8,3);
    #endif
    _cs = 1;
    WindowMax();
    return;
}

void SPI_TFT_ILI9341::vline(int x, int y0, int y1, int color)
{
    int h;
    h = y1 - y0 + 1;
    window(x,y0,1,h);
    wr_cmd(0x2C);  // send pixel
    #if defined TARGET_KL25Z  // 8 Bit SPI
    for (int y=0; y&lt;h; y++) {
        SPI::write(color &gt;&gt; 8);
        SPI::write(color &amp; 0xff);
    } 
    #else 
    SPI::format(16,3);                            // switch to 16 bit Mode 3
    for (int y=0; y&lt;h; y++) {
        SPI::write(color);
    }
    SPI::format(8,3);
    #endif
    _cs = 1;
    WindowMax();
    return;
}



void SPI_TFT_ILI9341::line(int x0, int y0, int x1, int y1, int color)
{
    //WindowMax();
    int   dx = 0, dy = 0;
    int   dx_sym = 0, dy_sym = 0;
    int   dx_x2 = 0, dy_x2 = 0;
    int   di = 0;

    dx = x1-x0;
    dy = y1-y0;

    if (dx == 0) {        /* vertical line */
        if (y1 &gt; y0) vline(x0,y0,y1,color);
        else vline(x0,y1,y0,color);
        return;
    }

    if (dx &gt; 0) {
        dx_sym = 1;
    } else {
        dx_sym = -1;
    }
    if (dy == 0) {        /* horizontal line */
        if (x1 &gt; x0) hline(x0,x1,y0,color);
        else  hline(x1,x0,y0,color);
        return;
    }

    if (dy &gt; 0) {
        dy_sym = 1;
    } else {
        dy_sym = -1;
    }

    dx = dx_sym*dx;
    dy = dy_sym*dy;

    dx_x2 = dx*2;
    dy_x2 = dy*2;

    if (dx &gt;= dy) {
        di = dy_x2 - dx;
        while (x0 != x1) {

            pixel(x0, y0, color);
            x0 += dx_sym;
            if (di&lt;0) {
                di += dy_x2;
            } else {
                di += dy_x2 - dx_x2;
                y0 += dy_sym;
            }
        }
        pixel(x0, y0, color);
    } else {
        di = dx_x2 - dy;
        while (y0 != y1) {
            pixel(x0, y0, color);
            y0 += dy_sym;
            if (di &lt; 0) {
                di += dx_x2;
            } else {
                di += dx_x2 - dy_x2;
                x0 += dx_sym;
            }
        }
        pixel(x0, y0, color);
    }
    return;
}


void SPI_TFT_ILI9341::rect(int x0, int y0, int x1, int y1, int color)
{

    if (x1 &gt; x0) hline(x0,x1,y0,color);
    else  hline(x1,x0,y0,color);

    if (y1 &gt; y0) vline(x0,y0,y1,color);
    else vline(x0,y1,y0,color);

    if (x1 &gt; x0) hline(x0,x1,y1,color);
    else  hline(x1,x0,y1,color);

    if (y1 &gt; y0) vline(x1,y0,y1,color);
    else vline(x1,y1,y0,color);

    return;
}



void SPI_TFT_ILI9341::fillrect(int x0, int y0, int x1, int y1, int color)
{

    int h = y1 - y0 + 1;
    int w = x1 - x0 + 1;
    int pixel = h * w;
    window(x0,y0,w,h);
    wr_cmd(0x2C);  // send pixel 
    #if defined TARGET_KL25Z  // 8 Bit SPI
    for (int p=0; p&lt;pixel; p++) {
        SPI::write(color &gt;&gt; 8);
        SPI::write(color &amp; 0xff);
    }
   #else
    SPI::format(16,3);                            // switch to 16 bit Mode 3
    for (int p=0; p&lt;pixel; p++) {
        SPI::write(color);
    }
    SPI::format(8,3);
    #endif
    _cs = 1;
    WindowMax();
    return;
}


void SPI_TFT_ILI9341::locate(int x, int y)
{
    char_x = x;
    char_y = y;
}



int SPI_TFT_ILI9341::columns()
{
    return width() / font[1];
}



int SPI_TFT_ILI9341::rows()
{
    return height() / font[2];
}



int SPI_TFT_ILI9341::_putc(int value)
{
    if (value == '\n') {    // new line
        char_x = 0;
        char_y = char_y + font[2];
        if (char_y &gt;= height() - font[2]) {
            char_y = 0;
        }
    } else {
        character(char_x, char_y, value);
    }
    return value;
}


void SPI_TFT_ILI9341::character(int x, int y, int c)
{
    unsigned int hor,vert,offset,bpl,j,i,b;
    unsigned char* zeichen;
    unsigned char z,w;

    if ((c &lt; 31) || (c &gt; 127)) return;   // test char range

    // read font parameter from start of array
    offset = font[0];                    // bytes / char
    hor = font[1];                       // get hor size of font
    vert = font[2];                      // get vert size of font
    bpl = font[3];                       // bytes per line

    if (char_x + hor &gt; width()) {
        char_x = 0;
        char_y = char_y + vert;
        if (char_y &gt;= height() - font[2]) {
            char_y = 0;
        }
    }
    window(char_x, char_y,hor,vert); // char box
    wr_cmd(0x2C);  // send pixel
    #ifndef TARGET_KL25Z  // 16 Bit SPI 
    SPI::format(16,3);   
    #endif                         // switch to 16 bit Mode 3
    zeichen = &amp;font[((c -32) * offset) + 4]; // start of char bitmap
    w = zeichen[0];                          // width of actual char
     for (j=0; j&lt;vert; j++) {  //  vert line
        for (i=0; i&lt;hor; i++) {   //  horz line
            z =  zeichen[bpl * i + ((j &amp; 0xF8) &gt;&gt; 3)+1];
            b = 1 &lt;&lt; (j &amp; 0x07);
            if (( z &amp; b ) == 0x00) {
               #ifndef TARGET_KL25Z  // 16 Bit SPI 
                SPI::write(_background);
               #else
                SPI::write(_background &gt;&gt; 8);
                SPI::write(_background &amp; 0xff);
                #endif
            } else {
                #ifndef TARGET_KL25Z  // 16 Bit SPI
                SPI::write(_foreground);
                #else
                SPI::write(_foreground &gt;&gt; 8);
                SPI::write(_foreground &amp; 0xff);
                #endif
            }
        }
    }
    _cs = 1;
    #ifndef TARGET_KL25Z  // 16 Bit SPI
    SPI::format(8,3);
    #endif
    WindowMax();
    if ((w + 2) &lt; hor) {                   // x offset to next char
        char_x += w + 2;
    } else char_x += hor;
}


void SPI_TFT_ILI9341::set_font(unsigned char* f)
{
    font = f;
}



void SPI_TFT_ILI9341::Bitmap(unsigned int x, unsigned int y, unsigned int w, unsigned int h,unsigned char *bitmap)
{
    unsigned int  j;
    int padd;
    unsigned short *bitmap_ptr = (unsigned short *)bitmap;
    #if defined TARGET_KL25Z  // 8 Bit SPI
        unsigned short pix_temp;
    #endif
    
    unsigned int i;
    
    // the lines are padded to multiple of 4 bytes in a bitmap
    padd = -1;
    do {
        padd ++;
    } while (2*(w + padd)%4 != 0);
    window(x, y, w, h);
    bitmap_ptr += ((h - 1)* (w + padd));
    wr_cmd(0x2C);  // send pixel
    #ifndef TARGET_KL25Z  // 16 Bit SPI 
    SPI::format(16,3);
    #endif                            // switch to 16 bit Mode 3
    for (j = 0; j &lt; h; j++) {         //Lines
        for (i = 0; i &lt; w; i++) {     // one line
            #if defined TARGET_KL25Z  // 8 Bit SPI
                pix_temp = *bitmap_ptr;
                SPI::write(pix_temp &gt;&gt; 8);
                SPI::write(pix_temp);
                bitmap_ptr++;
            #else
                SPI::write(*bitmap_ptr);    // one line
                bitmap_ptr++;
            #endif
        }
        bitmap_ptr -= 2*w;
        bitmap_ptr -= padd;
    }
    _cs = 1;
    #ifndef TARGET_KL25Z  // 16 Bit SPI 
    SPI::format(8,3);
    #endif
    WindowMax();
}


// local filesystem is not implemented in kinetis board , but you can add a SD card

int SPI_TFT_ILI9341::BMP_16(unsigned int x, unsigned int y, const char *Name_BMP)
{

#define OffsetPixelWidth    18
#define OffsetPixelHeigh    22
#define OffsetFileSize      34
#define OffsetPixData       10
#define OffsetBPP           28

    char filename[50];
    unsigned char BMP_Header[54];
    unsigned short BPP_t;
    unsigned int PixelWidth,PixelHeigh,start_data;
    unsigned int    i,off;
    int padd,j;
    unsigned short *line;

    // get the filename
    i=0;
    while (*Name_BMP!='\0') {
        filename[i++]=*Name_BMP++;
    }
    filename[i] = 0;  
    
    FILE *Image = fopen((const char *)&amp;filename[0], &quot;rb&quot;);  // open the bmp file
    if (!Image) {
        return(0);      // error file not found !
    }

    fread(&amp;BMP_Header[0],1,54,Image);      // get the BMP Header

    if (BMP_Header[0] != 0x42 || BMP_Header[1] != 0x4D) {  // check magic byte
        fclose(Image);
        return(-1);     // error no BMP file
    }

    BPP_t = BMP_Header[OffsetBPP] + (BMP_Header[OffsetBPP + 1] &lt;&lt; 8);
    if (BPP_t != 0x0010) {
        fclose(Image);
        return(-2);     // error no 16 bit BMP
    }

    PixelHeigh = BMP_Header[OffsetPixelHeigh] + (BMP_Header[OffsetPixelHeigh + 1] &lt;&lt; 8) + (BMP_Header[OffsetPixelHeigh + 2] &lt;&lt; 16) + (BMP_Header[OffsetPixelHeigh + 3] &lt;&lt; 24);
    PixelWidth = BMP_Header[OffsetPixelWidth] + (BMP_Header[OffsetPixelWidth + 1] &lt;&lt; 8) + (BMP_Header[OffsetPixelWidth + 2] &lt;&lt; 16) + (BMP_Header[OffsetPixelWidth + 3] &lt;&lt; 24);
    if (PixelHeigh &gt; height() + y || PixelWidth &gt; width() + x) {
        fclose(Image);
        return(-3);      // to big
    }

    start_data = BMP_Header[OffsetPixData] + (BMP_Header[OffsetPixData + 1] &lt;&lt; 8) + (BMP_Header[OffsetPixData + 2] &lt;&lt; 16) + (BMP_Header[OffsetPixData + 3] &lt;&lt; 24);

    line = (unsigned short *) malloc (2 * PixelWidth); // we need a buffer for a line
    if (line == NULL) {
        return(-4);         // error no memory
    }

    // the bmp lines are padded to multiple of 4 bytes
    padd = -1;
    do {
        padd ++;
    } while ((PixelWidth * 2 + padd)%4 != 0);

    window(x, y,PixelWidth ,PixelHeigh);
    wr_cmd(0x2C);  // send pixel
    #ifndef TARGET_KL25Z // only 8 Bit SPI 
    SPI::format(16,3);  
    #endif                          // switch to 16 bit Mode 3
    for (j = PixelHeigh - 1; j &gt;= 0; j--) {               //Lines bottom up
        off = j * (PixelWidth  * 2 + padd) + start_data;   // start of line
        fseek(Image, off ,SEEK_SET);
        fread(line,1,PixelWidth * 2,Image);       // read a line - slow 
        for (i = 0; i &lt; PixelWidth; i++) {        // copy pixel data to TFT
        #ifndef TARGET_KL25Z // only 8 Bit SPI
            SPI::write(line[i]);                  // one 16 bit pixel
        #else  
            SPI::write(line[i] &gt;&gt; 8);
            SPI::write(line[i]);
        #endif    
        } 
     }
    _cs = 1;
    SPI::format(8,3);
    free (line);
    fclose(Image);
    WindowMax();
    return(1);
}

#endif
            </pre>
    </div>

    </div>
</div>
            



    </div>

    <div class="three columns sidebar ">
        








<div class="panel">
    <h5 class="subheader">Repository toolbox</h5>
    <table id="repo_actions">
        <tr>
            <td>
                

<div id="import-button" class="import-button"></div>
<script type="text/javascript">
  new ImportButton($("#import-button"), {
    last_used_workspace: {
      type: "compiler"
    },
    compiler_import_url: "https://developer.mbed.org/compiler/#import:/users/dreschpe/code/SPI_TFT_ILI9341/;mode:lib",
    clone_url: "http://mbed.org/users/dreschpe/code/SPI_TFT_ILI9341/",
    is_library: true,
    c9_enabled: false,
    cli_enabled: true
  });
</script>

            </td>
        </tr>
        <tr>
        	<td>
    	    	<a style="width: 100%;"
                   class="button secondary small"
                   href="/users/dreschpe/code/SPI_TFT_ILI9341/export">
    	    		<span>
    	    			<i class="fa fa-cloud-download" aria-hidden="true"></i>
    	    			Export to desktop IDE
    	    		</span>
    	    	</a>
        	</td>
        </tr>

        

        

        

        

        

    </table>
</div>


<div class="panel">
    <h5 class="subheader">Repository details</h5>
    <table>
        
        <tr>
            <th>Type:</th>
            <td>
                <i class="fa fa-cog" aria-hidden="true"></i>
                Library
            </td>
        </tr>
        
        <tr>
            <th>Created:</th>
            <td><abbr class="timeago" title="2013-06-12T22:55:24+00:00">12 Jun 2013</abbr></td>
        </tr>
        <tr>
            <th>Imports:</th>
            <td>
                <a title="Number of times this repository has been imported"  href="/users/dreschpe/code/SPI_TFT_ILI9341/">
                    <i class="fa icon_imports" aria-hidden="true"></i>
                    1886
                </a>
            </td>
        </tr>
        <tr>
            <th>Forks:</th>
            <td>
                <a title="Copies of this repository"
                   href="/users/dreschpe/code/SPI_TFT_ILI9341/forks">
                    <i class="fa icon_repo_fork" aria-hidden="true"></i>
                    9
                </a>
            </td>
        </tr>
        <tr>
            <th width="40%">Commits:</th>
            <td>
                <a href="shortlog">
                    <i class="fa icon_commits" aria-hidden="true"></i>
                    14
                </a>
            </td>
        </tr>
        <tr>
            <th>Dependents:</th>
            <td>
                <a title="Programs or libraries which need this repository" href="/users/dreschpe/code/SPI_TFT_ILI9341/dependents">
                    <i class="fa icon_repo_depens" aria-hidden="true"></i>
                    38
                </a>
            </td>
        </tr>
        <tr>
            <th>Dependencies:</th>
            <td>
                <a title="Libraries which this program or library needs to function" href="/users/dreschpe/code/SPI_TFT_ILI9341/dependencies">
                    <i class="fa icon_repo_deps fa-flip-vertical" aria-hidden="true"></i>
                    0
                </a>
            </td>
        </tr>
        <tr>
            <th>Followers:</th>
            <td>
                <a title="Followers of this repository" href="/users/dreschpe/code/SPI_TFT_ILI9341/followers">
                    <i class="fa icon_add" aria-hidden="true"></i>
                    119
                </a>
            </td>
        </tr>
        
        <tr>
            <th>Issues:</th>
            <td>
                <a title="Issues" href="/users/dreschpe/code/SPI_TFT_ILI9341/issues">
                    <i class="fa fa-bug" aria-hidden="true"></i>
                    5
                </a>
            </td>
        </tr>
        
    </table>

    

</div>










<div class="panel">
    <h5 class="subheader">Components</h5>

    
        <a href="/components/Seeed-Studio-28-TFT-Touch-Shield-V20/">
            
                <img src="/media/cache/components/components/TFT_Shield.jpg.40x40_q85.jpg" style="vertical-align: middle;">
            Seeed Studio 2.8&#39;&#39; TFT Touch Shield V2.0
        </a>
    
        <a href="/components/22-QVGA-display-with-SD-card-socket/">
            
                <img src="/media/cache/components/components/tft3_1.jpg.40x40_q85.jpg" style="vertical-align: middle;">
            2.2 QVGA display with SD card socket
        </a>
    

    
</div>





    </div>
</div>


    <div class="row footer hide-on-print">
        <div class="twelve columns">
            <hr />
            <ul>
                <li>&copy; mbed</li>
                <li><a href="/blog">blog</a></li>
                <li><a href="/handbook/Jobs">we're hiring!</a></li>
                <li><a href="/handbook/Help">support</a></li>
                <li><a href="/handbook/Service-status">service status</a></li>
                <li><a href="/privacy">privacy policy</a></li>
                <li><a href="/terms">terms and conditions</a> </li>
            </ul>
       </div>
	</div>



<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try{
var pageTracker = _gat._getTracker("UA-1447836-8");

pageTracker._setCustomVar(1, 'User Type', 'Guest', 2);

pageTracker._trackPageview();
} catch(err) {}
</script>





<div id="cookiemodule">
    <div class="modouter">
        <div class="modinner">
            <h5>Important information</h5>
            <div class="modcontent">
                <div class="intro">
                    <p>This site uses cookies to store information on your computer. By continuing to use our site, you consent to our
                    <a href="/privacy/">cookies</a>.</p>
                </div>
                <div class="modopen">
                    <p><p style="margin: 0cm 0cm 0pt">ARM websites use two types of cookie: (<strong>1)</strong> those that enable the site to function and perform as required; and <b>(2)</b> analytical cookies which anonymously track visitors only while using the site. If you are not happy with this use of these cookies please review our <a  target="_self" href="/privacy/">Privacy Policy</a> to learn how they can be disabled. By disabling cookies some features of the site will not work.</p></p>
                </div>
                <button class="readmore">Read More</button>
                <button class="accept" id="">accept and hide this message</button>
            </div>
        </div>
    </div>
</div>

<script type="text/javascript">
jQuery(document).ready(function() {
    // cookie functions
    // based on http://www.quirksmode.org/js/cookies.html
    function create(name, value, days, path, domain) {
        path = typeof path !== 'undefined' ? path : '/';
        domain = typeof domain !== 'undefined' ? '; domain=' + domain : '';
        if (days) {
            var date = new Date();
            date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
            var expires = "; expires=" + date.toGMTString();
        } else {
            var expires = "";
        }
        document.cookie = name + "=" + value + expires + domain + "; path=" + path;
    }
    function read(name) {
        var nameEQ = name + "=";
        var ca = document.cookie.split(';');
        for (var i = 0; i < ca.length; i++) {
            var c = ca[i];
            while (c.charAt(0) == ' ') c = c.substring(1, c.length);
            if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length, c.length);
        }
        return null;
    }

    function erase(name) {
        create(name, "", -1);
    }

    create('testCookies', 'yes', 365, '/', '.mbed.org');
    if (read("testCookies") == 'yes' && read("acceptCookies") != 'yes') {
        jQuery('#cookiemodule').css('display', 'block');
        jQuery('button.readmore').click(function() {
            jQuery('.modopen').slideToggle('slow');
            if (jQuery(this).text() == "Read More") {
                jQuery(this).text("Read Less");
            } else {
                jQuery(this).text("Read More");
            };
        });

        jQuery('button.accept').click(function() {
            create('acceptCookies', 'yes', 365, '/', '.mbed.org');
            jQuery('#cookiemodule').fadeOut('slow');
        });

        jQuery('button.close').click(function() {
            jQuery('#cookiemodule').fadeOut('slow');
        });
    }
});
</script>


<div id="flag-content" class="reveal-modal small">
    <h2>Report Content</h2>
    <a class="close-reveal-modal">&#215;</a>
    <form action="" method="post" id="flag-content-form">
        <input type='hidden' name='csrfmiddlewaretoken' value='4rPh4NiRmvbwtqIWyQ4MOvC4xPbwJEDU' />
        <ul>
            <li>
                <label for="id_reason_1">
                    <input id="id_reason_1" name="reason" type="radio" value="1" />
                    Spam
                </label>
            </li>
            <li>
                <label for="id_reason_2">
                    <input id="id_reason_2" name="reason" type="radio" value="2" />
                    Inappropriate
                </label>
            </li>
        </ul>
        <a class="button secondary cancel-flag">Cancel</a>
        <input type="submit" value="Report" class="button" />
    </form>
</div>

<div id="access-warning-modal" class="reveal-modal">
    <h2>Access Warning</h2>
    <p>You do not have the correct permissions to perform this operation. Please, contact us at support@mbed.com to gain full access.</p>
    <a class="close-reveal-modal">&#215;</a>
</div>

</body>
</html>

