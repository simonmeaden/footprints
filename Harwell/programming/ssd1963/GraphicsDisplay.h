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
                    
                    <li><a href="/account/login/?next=/users/dreschpe/code/SPI_TFT_ILI9341/file/b2b3e5430f81/GraphicsDisplay.h">Log In/Signup</a></li>
                     
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
            <li class="current"><a href="/users/dreschpe/code/SPI_TFT_ILI9341/file/b2b3e5430f81/GraphicsDisplay.h">file</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/log/b2b3e5430f81/GraphicsDisplay.h">revisions</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/annotate/b2b3e5430f81/GraphicsDisplay.h">annotate</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/diff/b2b3e5430f81/GraphicsDisplay.h">diff</a></li>
            <li><a href="/users/dreschpe/code/SPI_TFT_ILI9341/raw-file/b2b3e5430f81/GraphicsDisplay.h">raw</a></li>
        </ul>

   <div class="module">

    <h2>GraphicsDisplay.h</h2>

    <dl class="overview ">
        <dt>Committer:</dt>
        <dd>dreschpe</dd>
        <dt>Date:</dt>
        <dd><abbr class="timeago" title="Wed Jun 25 16:51:27 2014 +0000">2014-06-25</abbr></dd>
        
        <dt>Revision:</dt>
        <dd><b><a class="list" href="/users/dreschpe/code/SPI_TFT_ILI9341/rev/#node|short#">13:b2b3e5430f81</a></b></dd>
        
        
    </dl>

    <div class="source">
     <h3>File content as of revision 13:b2b3e5430f81:</h3>
        <pre class="mbed-code">
/* mbed GraphicsDisplay Display Library Base Class
 * Copyright (c) 2007-2009 sford
 * Released under the MIT License: http://mbed.org/license/mit
 *
 * A library for providing a common base class for Graphics displays
 * To port a new display, derive from this class and implement
 * the constructor (setup the display), pixel (put a pixel
 * at a location), width and height functions. Everything else
 * (locate, printf, putc, cls, window, putp, fill, blit, blitbit) 
 * will come for free. You can also provide a specialised implementation
 * of window and putp to speed up the results
 */

#ifndef MBED_GRAPHICSDISPLAY_H
#define MBED_GRAPHICSDISPLAY_H

#include &quot;TextDisplay.h&quot;

class GraphicsDisplay : public TextDisplay {

public:         
          
    GraphicsDisplay(const char* name);
     
    virtual void pixel(int x, int y, int colour) = 0;
    virtual int width() = 0;
    virtual int height() = 0;
        
    virtual void window(unsigned int x,unsigned int y,unsigned int w,unsigned int h);
    virtual void putp(int colour);
    
    virtual void cls();
    virtual void fill(int x, int y, int w, int h, int colour);
    virtual void blit(int x, int y, int w, int h, const int *colour);    
    virtual void blitbit(int x, int y, int w, int h, const char* colour);
    
    virtual void character(int column, int row, int value);
    virtual int columns();
    virtual int rows();
    
protected:

    // pixel location
    short _x;
    short _y;
    
    // window location
    short _x1;
    short _x2;
    short _y1;
    short _y2;

};

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

