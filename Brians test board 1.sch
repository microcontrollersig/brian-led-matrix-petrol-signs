<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="RpiPico">
<packages>
<package name="PICO-PKG">
<wire x1="10.5" y1="-25.5" x2="10.5" y2="-24.63" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-23.63" x2="10.5" y2="-22.09" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-21.09" x2="10.5" y2="-19.55" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-18.55" x2="10.5" y2="-17.01" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-16.01" x2="10.5" y2="-14.47" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-13.47" x2="10.5" y2="-11.93" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-10.93" x2="10.5" y2="-9.39" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-8.39" x2="10.5" y2="-6.85" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-5.85" x2="10.5" y2="-4.31" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-3.31" x2="10.5" y2="-1.77" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-0.77" x2="10.5" y2="0.77" width="0.1524" layer="21"/>
<wire x1="10.5" y1="1.77" x2="10.5" y2="3.31" width="0.1524" layer="21"/>
<wire x1="10.5" y1="4.31" x2="10.5" y2="5.85" width="0.1524" layer="21"/>
<wire x1="10.5" y1="6.85" x2="10.5" y2="8.39" width="0.1524" layer="21"/>
<wire x1="10.5" y1="9.39" x2="10.5" y2="10.93" width="0.1524" layer="21"/>
<wire x1="10.5" y1="11.93" x2="10.5" y2="13.47" width="0.1524" layer="21"/>
<wire x1="10.5" y1="14.47" x2="10.5" y2="16.01" width="0.1524" layer="21"/>
<wire x1="10.5" y1="17.01" x2="10.5" y2="18.55" width="0.1524" layer="21"/>
<wire x1="10.5" y1="19.55" x2="10.5" y2="21.09" width="0.1524" layer="21"/>
<wire x1="10.5" y1="22.09" x2="10.5" y2="23.63" width="0.1524" layer="21"/>
<wire x1="10.5" y1="24.63" x2="10.5" y2="25.5" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="25.5" x2="-10.5" y2="24.63" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="23.63" x2="-10.5" y2="22.09" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="21.09" x2="-10.5" y2="19.55" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="18.55" x2="-10.5" y2="17.01" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="16.01" x2="-10.5" y2="14.47" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="13.47" x2="-10.5" y2="11.93" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="10.93" x2="-10.5" y2="9.39" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="8.39" x2="-10.5" y2="6.85" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="5.85" x2="-10.5" y2="4.31" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="3.31" x2="-10.5" y2="1.77" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="0.77" x2="-10.5" y2="-0.77" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-1.77" x2="-10.5" y2="-3.31" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-4.31" x2="-10.5" y2="-5.85" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-6.85" x2="-10.5" y2="-8.39" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-9.39" x2="-10.5" y2="-10.93" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-11.93" x2="-10.5" y2="-13.47" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-14.47" x2="-10.5" y2="-16.01" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-17.01" x2="-10.5" y2="-18.55" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-19.55" x2="-10.5" y2="-21.09" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-22.09" x2="-10.5" y2="-23.63" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-24.63" x2="-10.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-25.5" x2="3.04" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="2.04" y1="-25.5" x2="0.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="-25.5" x2="-2.04" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-3.04" y1="-25.5" x2="-10.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="25.5" x2="10.5" y2="25.5" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="24.13" drill="1"/>
<pad name="2" x="-8.89" y="21.59" drill="1"/>
<pad name="7" x="-8.89" y="8.89" drill="1"/>
<pad name="8" x="-8.89" y="6.35" drill="1"/>
<pad name="3" x="-8.89" y="19.05" drill="1"/>
<pad name="4" x="-8.89" y="16.51" drill="1"/>
<pad name="6" x="-8.89" y="11.43" drill="1"/>
<pad name="5" x="-8.89" y="13.97" drill="1"/>
<pad name="9" x="-8.89" y="3.81" drill="1"/>
<pad name="10" x="-8.89" y="1.27" drill="1"/>
<pad name="11" x="-8.89" y="-1.27" drill="1"/>
<pad name="12" x="-8.89" y="-3.81" drill="1"/>
<pad name="13" x="-8.89" y="-6.35" drill="1"/>
<pad name="14" x="-8.89" y="-8.89" drill="1"/>
<pad name="15" x="-8.89" y="-11.43" drill="1"/>
<pad name="16" x="-8.89" y="-13.97" drill="1"/>
<pad name="17" x="-8.89" y="-16.51" drill="1"/>
<pad name="18" x="-8.89" y="-19.05" drill="1"/>
<pad name="19" x="-8.89" y="-21.59" drill="1"/>
<pad name="20" x="-8.89" y="-24.13" drill="1"/>
<pad name="21" x="8.89" y="-24.13" drill="1"/>
<pad name="22" x="8.89" y="-21.59" drill="1"/>
<pad name="23" x="8.89" y="-19.05" drill="1"/>
<pad name="24" x="8.89" y="-16.51" drill="1"/>
<pad name="25" x="8.89" y="-13.97" drill="1"/>
<pad name="26" x="8.89" y="-11.43" drill="1"/>
<pad name="27" x="8.89" y="-8.89" drill="1"/>
<pad name="28" x="8.89" y="-6.35" drill="1"/>
<pad name="29" x="8.89" y="-3.81" drill="1"/>
<pad name="30" x="8.89" y="-1.27" drill="1"/>
<pad name="31" x="8.89" y="1.27" drill="1"/>
<pad name="32" x="8.89" y="3.81" drill="1"/>
<pad name="33" x="8.89" y="6.35" drill="1"/>
<pad name="34" x="8.89" y="8.89" drill="1"/>
<pad name="35" x="8.89" y="11.43" drill="1"/>
<pad name="36" x="8.89" y="13.97" drill="1"/>
<pad name="37" x="8.89" y="16.51" drill="1"/>
<pad name="38" x="8.89" y="19.05" drill="1"/>
<pad name="39" x="8.89" y="21.59" drill="1"/>
<pad name="40" x="8.89" y="24.13" drill="1"/>
<text x="-10.414" y="-28.067" size="1.778" layer="25">&gt;NAME</text>
<text x="1.016" y="-20.955" size="1.778" layer="27" rot="R90">&gt;VALUE</text>
<smd name="P$1" x="-10" y="24.13" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$2" x="-10" y="21.59" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$3" x="-10" y="19.05" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$4" x="-10" y="16.51" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$5" x="-10" y="13.97" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$6" x="-10" y="11.43" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$7" x="-10" y="8.89" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$8" x="-10" y="6.35" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$9" x="-10" y="3.81" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$10" x="-10" y="1.27" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$11" x="-10" y="-1.27" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$12" x="-10" y="-3.81" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$13" x="-10" y="-6.35" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$14" x="-10" y="-8.89" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$15" x="-10" y="-11.43" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$16" x="-10" y="-13.97" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$17" x="-10" y="-16.51" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$18" x="-10" y="-19.05" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$19" x="-10" y="-21.59" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$20" x="-10" y="-24.13" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$21" x="10" y="-24.13" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$22" x="10" y="-21.59" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$23" x="10" y="-19.05" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$24" x="10" y="-16.51" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$25" x="10" y="-13.97" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$26" x="10" y="-11.43" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$27" x="10" y="-8.89" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$28" x="10" y="-6.35" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$29" x="10" y="-3.81" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$30" x="10" y="-1.27" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$31" x="10" y="1.27" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$32" x="10" y="3.81" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$33" x="10" y="6.35" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$34" x="10" y="8.89" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$35" x="10" y="11.43" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$36" x="10" y="13.97" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$37" x="10" y="16.51" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$38" x="10" y="19.05" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$39" x="10" y="21.59" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$40" x="10" y="24.13" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<hole x="-2.725" y="24" drill="1.8"/>
<hole x="2.725" y="24" drill="1.8"/>
<hole x="-2.425" y="20.97" drill="1.5"/>
<hole x="2.425" y="20.97" drill="1.5"/>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="18.5"/>
<vertex x="-1.5" y="18.5"/>
<vertex x="-1.5" y="16.5"/>
<vertex x="-3.5" y="16.5"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="16"/>
<vertex x="-1.5" y="16"/>
<vertex x="-1.5" y="14"/>
<vertex x="-3.5" y="14"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="13.5"/>
<vertex x="-1.5" y="13.5"/>
<vertex x="-1.5" y="11.5"/>
<vertex x="-3.5" y="11.5"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.7" y="24.9"/>
<vertex x="3.7" y="24.9"/>
<vertex x="3.7" y="20.2"/>
<vertex x="-3.7" y="20.2"/>
</polygon>
<pad name="41" x="-2.54" y="-23.9" drill="1"/>
<pad name="42" x="0" y="-23.9" drill="1"/>
<pad name="43" x="2.54" y="-23.9" drill="1"/>
<smd name="P$41" x="-2.54" y="-24.925" dx="3.5" dy="1.7" layer="1" rot="R270"/>
<smd name="P$42" x="0" y="-24.925" dx="3.5" dy="1.7" layer="1" rot="R270"/>
<smd name="P$43" x="2.54" y="-24.925" dx="3.5" dy="1.7" layer="1" rot="R270"/>
<circle x="-12.7" y="25.4" radius="0.635" width="0" layer="21"/>
<wire x1="-4" y1="26.8" x2="4" y2="26.8" width="0.127" layer="21"/>
<wire x1="4" y1="26.8" x2="4" y2="20" width="0.127" layer="21"/>
<wire x1="4" y1="20" x2="-4" y2="20" width="0.127" layer="21"/>
<wire x1="-4" y1="20" x2="-4" y2="26.8" width="0.127" layer="21"/>
<wire x1="-10.5" y1="22.09" x2="-10.5" y2="21.09" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="24.63" x2="-10.5" y2="23.63" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="19.55" x2="-10.5" y2="18.55" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="17.01" x2="-10.5" y2="16.01" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="14.47" x2="-10.5" y2="13.47" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="11.93" x2="-10.5" y2="10.93" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="9.39" x2="-10.5" y2="8.39" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="6.85" x2="-10.5" y2="5.85" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="4.31" x2="-10.5" y2="3.31" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="1.77" x2="-10.5" y2="0.77" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-0.77" x2="-10.5" y2="-1.77" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-3.31" x2="-10.5" y2="-4.31" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-5.85" x2="-10.5" y2="-6.85" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-8.39" x2="-10.5" y2="-9.39" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-10.93" x2="-10.5" y2="-11.93" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-13.47" x2="-10.5" y2="-14.47" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-16.01" x2="-10.5" y2="-17.01" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-18.55" x2="-10.5" y2="-19.55" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-21.09" x2="-10.5" y2="-22.09" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-23.63" x2="-10.5" y2="-24.63" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-24.63" x2="10.5" y2="-23.63" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-22.09" x2="10.5" y2="-21.09" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-19.55" x2="10.5" y2="-18.55" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-17.01" x2="10.5" y2="-16.01" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-14.47" x2="10.5" y2="-13.47" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-11.93" x2="10.5" y2="-10.93" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-9.39" x2="10.5" y2="-8.39" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-6.85" x2="10.5" y2="-5.85" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-4.31" x2="10.5" y2="-3.31" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-1.77" x2="10.5" y2="-0.77" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="0.77" x2="10.5" y2="1.77" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="3.31" x2="10.5" y2="4.31" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="5.85" x2="10.5" y2="6.85" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="8.39" x2="10.5" y2="9.39" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="10.93" x2="10.5" y2="11.93" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="13.47" x2="10.5" y2="14.47" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="16.01" x2="10.5" y2="17.01" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="18.55" x2="10.5" y2="19.55" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="21.09" x2="10.5" y2="22.09" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="23.63" x2="10.5" y2="24.63" width="0.127" layer="21" curve="-180"/>
<wire x1="-0.5" y1="-25.5" x2="0.5" y2="-25.5" width="0.127" layer="21" curve="-180"/>
<wire x1="2.04" y1="-25.5" x2="3.04" y2="-25.5" width="0.127" layer="21" curve="-180"/>
<wire x1="-3.04" y1="-25.5" x2="-2.04" y2="-25.5" width="0.127" layer="21" curve="-180"/>
</package>
<package name="PICO-PKG-SMD">
<wire x1="-10.5" y1="25.5" x2="10.5" y2="25.5" width="0.1524" layer="21"/>
<text x="-10.414" y="-28.067" size="1.778" layer="25">&gt;NAME</text>
<text x="1.016" y="-20.955" size="1.778" layer="27" rot="R90">&gt;VALUE</text>
<smd name="P$1" x="-10" y="24.13" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$2" x="-10" y="21.59" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$3" x="-10" y="19.05" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$4" x="-10" y="16.51" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$5" x="-10" y="13.97" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$6" x="-10" y="11.43" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$7" x="-10" y="8.89" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$8" x="-10" y="6.35" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$9" x="-10" y="3.81" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$10" x="-10" y="1.27" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$11" x="-10" y="-1.27" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$12" x="-10" y="-3.81" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$13" x="-10" y="-6.35" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$14" x="-10" y="-8.89" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$15" x="-10" y="-11.43" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$16" x="-10" y="-13.97" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$17" x="-10" y="-16.51" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$18" x="-10" y="-19.05" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$19" x="-10" y="-21.59" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$20" x="-10" y="-24.13" dx="3.5" dy="1.7" layer="1"/>
<smd name="P$21" x="10" y="-24.13" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$22" x="10" y="-21.59" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$23" x="10" y="-19.05" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$24" x="10" y="-16.51" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$25" x="10" y="-13.97" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$26" x="10" y="-11.43" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$27" x="10" y="-8.89" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$28" x="10" y="-6.35" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$29" x="10" y="-3.81" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$30" x="10" y="-1.27" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$31" x="10" y="1.27" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$32" x="10" y="3.81" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$33" x="10" y="6.35" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$34" x="10" y="8.89" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$35" x="10" y="11.43" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$36" x="10" y="13.97" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$37" x="10" y="16.51" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$38" x="10" y="19.05" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$39" x="10" y="21.59" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<smd name="P$40" x="10" y="24.13" dx="3.5" dy="1.7" layer="1" rot="R180"/>
<hole x="-2.725" y="24" drill="1.8"/>
<hole x="2.725" y="24" drill="1.8"/>
<hole x="-2.425" y="20.97" drill="1.5"/>
<hole x="2.425" y="20.97" drill="1.5"/>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="18.5"/>
<vertex x="-1.5" y="18.5"/>
<vertex x="-1.5" y="16.5"/>
<vertex x="-3.5" y="16.5"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="16"/>
<vertex x="-1.5" y="16"/>
<vertex x="-1.5" y="14"/>
<vertex x="-3.5" y="14"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="13.5"/>
<vertex x="-1.5" y="13.5"/>
<vertex x="-1.5" y="11.5"/>
<vertex x="-3.5" y="11.5"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.7" y="24.9"/>
<vertex x="3.7" y="24.9"/>
<vertex x="3.7" y="20.2"/>
<vertex x="-3.7" y="20.2"/>
</polygon>
<smd name="P$41" x="-2.54" y="-24.925" dx="3.5" dy="1.7" layer="1" rot="R270"/>
<smd name="P$42" x="0" y="-24.925" dx="3.5" dy="1.7" layer="1" rot="R270"/>
<smd name="P$43" x="2.54" y="-24.925" dx="3.5" dy="1.7" layer="1" rot="R270"/>
<circle x="-12.7" y="25.4" radius="0.635" width="0" layer="21"/>
<wire x1="-4" y1="26.8" x2="4" y2="26.8" width="0.127" layer="21"/>
<wire x1="4" y1="26.8" x2="4" y2="20" width="0.127" layer="21"/>
<wire x1="4" y1="20" x2="-4" y2="20" width="0.127" layer="21"/>
<wire x1="-4" y1="20" x2="-4" y2="26.8" width="0.127" layer="21"/>
<wire x1="10.5" y1="-25.5" x2="10.5" y2="-24.63" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-23.63" x2="10.5" y2="-22.09" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-21.09" x2="10.5" y2="-19.55" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-18.55" x2="10.5" y2="-17.01" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-16.01" x2="10.5" y2="-14.47" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-13.47" x2="10.5" y2="-11.93" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-10.93" x2="10.5" y2="-9.39" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-8.39" x2="10.5" y2="-6.85" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-5.85" x2="10.5" y2="-4.31" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-3.31" x2="10.5" y2="-1.77" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-0.77" x2="10.5" y2="0.77" width="0.1524" layer="21"/>
<wire x1="10.5" y1="1.77" x2="10.5" y2="3.31" width="0.1524" layer="21"/>
<wire x1="10.5" y1="4.31" x2="10.5" y2="5.85" width="0.1524" layer="21"/>
<wire x1="10.5" y1="6.85" x2="10.5" y2="8.39" width="0.1524" layer="21"/>
<wire x1="10.5" y1="9.39" x2="10.5" y2="10.93" width="0.1524" layer="21"/>
<wire x1="10.5" y1="11.93" x2="10.5" y2="13.47" width="0.1524" layer="21"/>
<wire x1="10.5" y1="14.47" x2="10.5" y2="16.01" width="0.1524" layer="21"/>
<wire x1="10.5" y1="17.01" x2="10.5" y2="18.55" width="0.1524" layer="21"/>
<wire x1="10.5" y1="19.55" x2="10.5" y2="21.09" width="0.1524" layer="21"/>
<wire x1="10.5" y1="22.09" x2="10.5" y2="23.63" width="0.1524" layer="21"/>
<wire x1="10.5" y1="24.63" x2="10.5" y2="25.5" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="25.5" x2="-10.5" y2="24.63" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="23.63" x2="-10.5" y2="22.09" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="21.09" x2="-10.5" y2="19.55" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="18.55" x2="-10.5" y2="17.01" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="16.01" x2="-10.5" y2="14.47" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="13.47" x2="-10.5" y2="11.93" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="10.93" x2="-10.5" y2="9.39" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="8.39" x2="-10.5" y2="6.85" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="5.85" x2="-10.5" y2="4.31" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="3.31" x2="-10.5" y2="1.77" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="0.77" x2="-10.5" y2="-0.77" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-1.77" x2="-10.5" y2="-3.31" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-4.31" x2="-10.5" y2="-5.85" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-6.85" x2="-10.5" y2="-8.39" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-9.39" x2="-10.5" y2="-10.93" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-11.93" x2="-10.5" y2="-13.47" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-14.47" x2="-10.5" y2="-16.01" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-17.01" x2="-10.5" y2="-18.55" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-19.55" x2="-10.5" y2="-21.09" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-22.09" x2="-10.5" y2="-23.63" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-24.63" x2="-10.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-25.5" x2="3.04" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="2.04" y1="-25.5" x2="0.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="-25.5" x2="-2.04" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-3.04" y1="-25.5" x2="-10.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="22.09" x2="-10.5" y2="21.09" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="24.63" x2="-10.5" y2="23.63" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="19.55" x2="-10.5" y2="18.55" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="17.01" x2="-10.5" y2="16.01" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="14.47" x2="-10.5" y2="13.47" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="11.93" x2="-10.5" y2="10.93" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="9.39" x2="-10.5" y2="8.39" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="6.85" x2="-10.5" y2="5.85" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="4.31" x2="-10.5" y2="3.31" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="1.77" x2="-10.5" y2="0.77" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-0.77" x2="-10.5" y2="-1.77" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-3.31" x2="-10.5" y2="-4.31" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-5.85" x2="-10.5" y2="-6.85" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-8.39" x2="-10.5" y2="-9.39" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-10.93" x2="-10.5" y2="-11.93" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-13.47" x2="-10.5" y2="-14.47" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-16.01" x2="-10.5" y2="-17.01" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-18.55" x2="-10.5" y2="-19.55" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-21.09" x2="-10.5" y2="-22.09" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-23.63" x2="-10.5" y2="-24.63" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-24.63" x2="10.5" y2="-23.63" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-22.09" x2="10.5" y2="-21.09" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-19.55" x2="10.5" y2="-18.55" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-17.01" x2="10.5" y2="-16.01" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-14.47" x2="10.5" y2="-13.47" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-11.93" x2="10.5" y2="-10.93" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-9.39" x2="10.5" y2="-8.39" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-6.85" x2="10.5" y2="-5.85" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-4.31" x2="10.5" y2="-3.31" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-1.77" x2="10.5" y2="-0.77" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="0.77" x2="10.5" y2="1.77" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="3.31" x2="10.5" y2="4.31" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="5.85" x2="10.5" y2="6.85" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="8.39" x2="10.5" y2="9.39" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="10.93" x2="10.5" y2="11.93" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="13.47" x2="10.5" y2="14.47" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="16.01" x2="10.5" y2="17.01" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="18.55" x2="10.5" y2="19.55" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="21.09" x2="10.5" y2="22.09" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="23.63" x2="10.5" y2="24.63" width="0.127" layer="21" curve="-180"/>
<wire x1="-0.5" y1="-25.5" x2="0.5" y2="-25.5" width="0.127" layer="21" curve="-180"/>
<wire x1="2.04" y1="-25.5" x2="3.04" y2="-25.5" width="0.127" layer="21" curve="-180"/>
<wire x1="-3.04" y1="-25.5" x2="-2.04" y2="-25.5" width="0.127" layer="21" curve="-180"/>
</package>
<package name="PICO-PKG-TH">
<wire x1="-10.5" y1="25.5" x2="10.5" y2="25.5" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="24.13" drill="1"/>
<pad name="2" x="-8.89" y="21.59" drill="1"/>
<pad name="7" x="-8.89" y="8.89" drill="1"/>
<pad name="8" x="-8.89" y="6.35" drill="1"/>
<pad name="3" x="-8.89" y="19.05" drill="1"/>
<pad name="4" x="-8.89" y="16.51" drill="1"/>
<pad name="6" x="-8.89" y="11.43" drill="1"/>
<pad name="5" x="-8.89" y="13.97" drill="1"/>
<pad name="9" x="-8.89" y="3.81" drill="1"/>
<pad name="10" x="-8.89" y="1.27" drill="1"/>
<pad name="11" x="-8.89" y="-1.27" drill="1"/>
<pad name="12" x="-8.89" y="-3.81" drill="1"/>
<pad name="13" x="-8.89" y="-6.35" drill="1"/>
<pad name="14" x="-8.89" y="-8.89" drill="1"/>
<pad name="15" x="-8.89" y="-11.43" drill="1"/>
<pad name="16" x="-8.89" y="-13.97" drill="1"/>
<pad name="17" x="-8.89" y="-16.51" drill="1"/>
<pad name="18" x="-8.89" y="-19.05" drill="1"/>
<pad name="19" x="-8.89" y="-21.59" drill="1"/>
<pad name="20" x="-8.89" y="-24.13" drill="1"/>
<pad name="21" x="8.89" y="-24.13" drill="1"/>
<pad name="22" x="8.89" y="-21.59" drill="1"/>
<pad name="23" x="8.89" y="-19.05" drill="1"/>
<pad name="24" x="8.89" y="-16.51" drill="1"/>
<pad name="25" x="8.89" y="-13.97" drill="1"/>
<pad name="26" x="8.89" y="-11.43" drill="1"/>
<pad name="27" x="8.89" y="-8.89" drill="1"/>
<pad name="28" x="8.89" y="-6.35" drill="1"/>
<pad name="29" x="8.89" y="-3.81" drill="1"/>
<pad name="30" x="8.89" y="-1.27" drill="1"/>
<pad name="31" x="8.89" y="1.27" drill="1"/>
<pad name="32" x="8.89" y="3.81" drill="1"/>
<pad name="33" x="8.89" y="6.35" drill="1"/>
<pad name="34" x="8.89" y="8.89" drill="1"/>
<pad name="35" x="8.89" y="11.43" drill="1"/>
<pad name="36" x="8.89" y="13.97" drill="1"/>
<pad name="37" x="8.89" y="16.51" drill="1"/>
<pad name="38" x="8.89" y="19.05" drill="1"/>
<pad name="39" x="8.89" y="21.59" drill="1"/>
<pad name="40" x="8.89" y="24.13" drill="1"/>
<text x="-10.414" y="-28.067" size="1.778" layer="25">&gt;NAME</text>
<text x="1.016" y="-20.955" size="1.778" layer="27" rot="R90">&gt;VALUE</text>
<hole x="-2.725" y="24" drill="1.8"/>
<hole x="2.725" y="24" drill="1.8"/>
<hole x="-2.425" y="20.97" drill="1.5"/>
<hole x="2.425" y="20.97" drill="1.5"/>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="18.5"/>
<vertex x="-1.5" y="18.5"/>
<vertex x="-1.5" y="16.5"/>
<vertex x="-3.5" y="16.5"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="16"/>
<vertex x="-1.5" y="16"/>
<vertex x="-1.5" y="14"/>
<vertex x="-3.5" y="14"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.5" y="13.5"/>
<vertex x="-1.5" y="13.5"/>
<vertex x="-1.5" y="11.5"/>
<vertex x="-3.5" y="11.5"/>
</polygon>
<polygon width="0.127" layer="41">
<vertex x="-3.7" y="24.9"/>
<vertex x="3.7" y="24.9"/>
<vertex x="3.7" y="20.2"/>
<vertex x="-3.7" y="20.2"/>
</polygon>
<pad name="41" x="-2.54" y="-23.9" drill="1"/>
<pad name="42" x="0" y="-23.9" drill="1"/>
<pad name="43" x="2.54" y="-23.9" drill="1"/>
<circle x="-12.7" y="25.4" radius="0.635" width="0" layer="21"/>
<wire x1="-4" y1="26.8" x2="4" y2="26.8" width="0.127" layer="21"/>
<wire x1="4" y1="26.8" x2="4" y2="20" width="0.127" layer="21"/>
<wire x1="4" y1="20" x2="-4" y2="20" width="0.127" layer="21"/>
<wire x1="-4" y1="20" x2="-4" y2="26.8" width="0.127" layer="21"/>
<wire x1="10.5" y1="-25.5" x2="10.5" y2="-24.63" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-23.63" x2="10.5" y2="-22.09" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-21.09" x2="10.5" y2="-19.55" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-18.55" x2="10.5" y2="-17.01" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-16.01" x2="10.5" y2="-14.47" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-13.47" x2="10.5" y2="-11.93" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-10.93" x2="10.5" y2="-9.39" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-8.39" x2="10.5" y2="-6.85" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-5.85" x2="10.5" y2="-4.31" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-3.31" x2="10.5" y2="-1.77" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-0.77" x2="10.5" y2="0.77" width="0.1524" layer="21"/>
<wire x1="10.5" y1="1.77" x2="10.5" y2="3.31" width="0.1524" layer="21"/>
<wire x1="10.5" y1="4.31" x2="10.5" y2="5.85" width="0.1524" layer="21"/>
<wire x1="10.5" y1="6.85" x2="10.5" y2="8.39" width="0.1524" layer="21"/>
<wire x1="10.5" y1="9.39" x2="10.5" y2="10.93" width="0.1524" layer="21"/>
<wire x1="10.5" y1="11.93" x2="10.5" y2="13.47" width="0.1524" layer="21"/>
<wire x1="10.5" y1="14.47" x2="10.5" y2="16.01" width="0.1524" layer="21"/>
<wire x1="10.5" y1="17.01" x2="10.5" y2="18.55" width="0.1524" layer="21"/>
<wire x1="10.5" y1="19.55" x2="10.5" y2="21.09" width="0.1524" layer="21"/>
<wire x1="10.5" y1="22.09" x2="10.5" y2="23.63" width="0.1524" layer="21"/>
<wire x1="10.5" y1="24.63" x2="10.5" y2="25.5" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="25.5" x2="-10.5" y2="24.63" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="23.63" x2="-10.5" y2="22.09" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="21.09" x2="-10.5" y2="19.55" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="18.55" x2="-10.5" y2="17.01" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="16.01" x2="-10.5" y2="14.47" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="13.47" x2="-10.5" y2="11.93" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="10.93" x2="-10.5" y2="9.39" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="8.39" x2="-10.5" y2="6.85" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="5.85" x2="-10.5" y2="4.31" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="3.31" x2="-10.5" y2="1.77" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="0.77" x2="-10.5" y2="-0.77" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-1.77" x2="-10.5" y2="-3.31" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-4.31" x2="-10.5" y2="-5.85" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-6.85" x2="-10.5" y2="-8.39" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-9.39" x2="-10.5" y2="-10.93" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-11.93" x2="-10.5" y2="-13.47" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-14.47" x2="-10.5" y2="-16.01" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-17.01" x2="-10.5" y2="-18.55" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-19.55" x2="-10.5" y2="-21.09" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-22.09" x2="-10.5" y2="-23.63" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="-24.63" x2="-10.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="10.5" y1="-25.5" x2="3.04" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="2.04" y1="-25.5" x2="0.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="-25.5" x2="-2.04" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-3.04" y1="-25.5" x2="-10.5" y2="-25.5" width="0.1524" layer="21"/>
<wire x1="-10.5" y1="22.09" x2="-10.5" y2="21.09" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="24.63" x2="-10.5" y2="23.63" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="19.55" x2="-10.5" y2="18.55" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="17.01" x2="-10.5" y2="16.01" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="14.47" x2="-10.5" y2="13.47" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="11.93" x2="-10.5" y2="10.93" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="9.39" x2="-10.5" y2="8.39" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="6.85" x2="-10.5" y2="5.85" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="4.31" x2="-10.5" y2="3.31" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="1.77" x2="-10.5" y2="0.77" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-0.77" x2="-10.5" y2="-1.77" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-3.31" x2="-10.5" y2="-4.31" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-5.85" x2="-10.5" y2="-6.85" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-8.39" x2="-10.5" y2="-9.39" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-10.93" x2="-10.5" y2="-11.93" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-13.47" x2="-10.5" y2="-14.47" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-16.01" x2="-10.5" y2="-17.01" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-18.55" x2="-10.5" y2="-19.55" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-21.09" x2="-10.5" y2="-22.09" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.5" y1="-23.63" x2="-10.5" y2="-24.63" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-24.63" x2="10.5" y2="-23.63" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-22.09" x2="10.5" y2="-21.09" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-19.55" x2="10.5" y2="-18.55" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-17.01" x2="10.5" y2="-16.01" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-14.47" x2="10.5" y2="-13.47" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-11.93" x2="10.5" y2="-10.93" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-9.39" x2="10.5" y2="-8.39" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-6.85" x2="10.5" y2="-5.85" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-4.31" x2="10.5" y2="-3.31" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="-1.77" x2="10.5" y2="-0.77" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="0.77" x2="10.5" y2="1.77" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="3.31" x2="10.5" y2="4.31" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="5.85" x2="10.5" y2="6.85" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="8.39" x2="10.5" y2="9.39" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="10.93" x2="10.5" y2="11.93" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="13.47" x2="10.5" y2="14.47" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="16.01" x2="10.5" y2="17.01" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="18.55" x2="10.5" y2="19.55" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="21.09" x2="10.5" y2="22.09" width="0.127" layer="21" curve="-180"/>
<wire x1="10.5" y1="23.63" x2="10.5" y2="24.63" width="0.127" layer="21" curve="-180"/>
<wire x1="-0.5" y1="-25.5" x2="0.5" y2="-25.5" width="0.127" layer="21" curve="-180"/>
<wire x1="2.04" y1="-25.5" x2="3.04" y2="-25.5" width="0.127" layer="21" curve="-180"/>
<wire x1="-3.04" y1="-25.5" x2="-2.04" y2="-25.5" width="0.127" layer="21" curve="-180"/>
</package>
</packages>
<symbols>
<symbol name="PICO-SYM">
<pin name="GP0" x="-17.78" y="25.4" length="middle"/>
<pin name="GP1" x="-17.78" y="22.86" length="middle"/>
<pin name="GP2" x="-17.78" y="17.78" length="middle"/>
<pin name="GP3" x="-17.78" y="15.24" length="middle"/>
<pin name="GP4" x="-17.78" y="12.7" length="middle"/>
<pin name="GP5" x="-17.78" y="10.16" length="middle"/>
<pin name="GP6" x="-17.78" y="5.08" length="middle"/>
<pin name="GP7" x="-17.78" y="2.54" length="middle"/>
<pin name="GP8" x="-17.78" y="0" length="middle"/>
<pin name="GP9" x="-17.78" y="-2.54" length="middle"/>
<pin name="GP10" x="-17.78" y="-7.62" length="middle"/>
<pin name="GP11" x="-17.78" y="-10.16" length="middle"/>
<pin name="GP12" x="-17.78" y="-12.7" length="middle"/>
<pin name="GP13" x="-17.78" y="-15.24" length="middle"/>
<pin name="GP14" x="-17.78" y="-20.32" length="middle"/>
<pin name="GP15" x="-17.78" y="-22.86" length="middle"/>
<pin name="GP16" x="17.78" y="-22.86" length="middle" rot="R180"/>
<pin name="GP17" x="17.78" y="-20.32" length="middle" rot="R180"/>
<pin name="GP18" x="17.78" y="-15.24" length="middle" rot="R180"/>
<pin name="GP19" x="17.78" y="-12.7" length="middle" rot="R180"/>
<pin name="GP20" x="17.78" y="-10.16" length="middle" rot="R180"/>
<pin name="GP21" x="17.78" y="-7.62" length="middle" rot="R180"/>
<pin name="GP22" x="17.78" y="-2.54" length="middle" rot="R180"/>
<pin name="RUN" x="17.78" y="22.86" length="middle" direction="in" rot="R180"/>
<pin name="GP26" x="17.78" y="2.54" length="middle" rot="R180"/>
<pin name="GP27" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="GP28" x="17.78" y="10.16" length="middle" rot="R180"/>
<pin name="ADC_REF" x="17.78" y="17.78" length="middle" direction="in" rot="R180"/>
<pin name="3V3(OUT)" x="17.78" y="30.48" length="middle" direction="pwr" rot="R180"/>
<pin name="3V3_EN" x="17.78" y="25.4" length="middle" direction="in" rot="R180"/>
<pin name="GND" x="17.78" y="-35.56" length="middle" direction="pwr" rot="R180"/>
<pin name="VSYS" x="17.78" y="33.02" length="middle" direction="pwr" rot="R180"/>
<pin name="VBUS" x="17.78" y="35.56" length="middle" direction="pwr" rot="R180"/>
<wire x1="-12.7" y1="38.1" x2="12.7" y2="38.1" width="0.254" layer="94"/>
<wire x1="12.7" y1="38.1" x2="12.7" y2="-38.1" width="0.254" layer="94"/>
<wire x1="12.7" y1="-38.1" x2="-12.7" y2="-38.1" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-38.1" x2="-12.7" y2="38.1" width="0.254" layer="94"/>
<text x="-12.7155" y="39.4146" size="2.54388125" layer="95">&gt;NAME</text>
<text x="-12.7069" y="-41.9314" size="2.54171875" layer="96">&gt;VALUE</text>
<pin name="SWDIO" x="-17.78" y="-35.56" length="middle"/>
<pin name="SWGND" x="-17.78" y="-33.02" length="middle" direction="pwr"/>
<pin name="SWCLK" x="-17.78" y="-30.48" length="middle" direction="in"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="RASPBERRY_PICO" prefix="U">
<description>Raspberry Pi Pico</description>
<gates>
<gate name="U$1" symbol="PICO-SYM" x="0" y="-20.32"/>
</gates>
<devices>
<device name="SMD-TH" package="PICO-PKG">
<connects>
<connect gate="U$1" pin="3V3(OUT)" pad="36 P$36"/>
<connect gate="U$1" pin="3V3_EN" pad="37 P$37"/>
<connect gate="U$1" pin="ADC_REF" pad="35 P$35"/>
<connect gate="U$1" pin="GND" pad="3 8 13 18 23 28 33 38 P$3 P$8 P$13 P$18 P$23 P$28 P$33 P$38"/>
<connect gate="U$1" pin="GP0" pad="1 P$1"/>
<connect gate="U$1" pin="GP1" pad="2 P$2"/>
<connect gate="U$1" pin="GP10" pad="14 P$14"/>
<connect gate="U$1" pin="GP11" pad="15 P$15"/>
<connect gate="U$1" pin="GP12" pad="16 P$16"/>
<connect gate="U$1" pin="GP13" pad="17 P$17"/>
<connect gate="U$1" pin="GP14" pad="19 P$19"/>
<connect gate="U$1" pin="GP15" pad="20 P$20"/>
<connect gate="U$1" pin="GP16" pad="21 P$21"/>
<connect gate="U$1" pin="GP17" pad="22 P$22"/>
<connect gate="U$1" pin="GP18" pad="24 P$24"/>
<connect gate="U$1" pin="GP19" pad="25 P$25"/>
<connect gate="U$1" pin="GP2" pad="4 P$4"/>
<connect gate="U$1" pin="GP20" pad="26 P$26"/>
<connect gate="U$1" pin="GP21" pad="27 P$27"/>
<connect gate="U$1" pin="GP22" pad="29 P$29"/>
<connect gate="U$1" pin="GP26" pad="31 P$31"/>
<connect gate="U$1" pin="GP27" pad="32 P$32"/>
<connect gate="U$1" pin="GP28" pad="34 P$34"/>
<connect gate="U$1" pin="GP3" pad="5 P$5"/>
<connect gate="U$1" pin="GP4" pad="6 P$6"/>
<connect gate="U$1" pin="GP5" pad="7 P$7"/>
<connect gate="U$1" pin="GP6" pad="9 P$9"/>
<connect gate="U$1" pin="GP7" pad="10 P$10"/>
<connect gate="U$1" pin="GP8" pad="11 P$11"/>
<connect gate="U$1" pin="GP9" pad="12 P$12"/>
<connect gate="U$1" pin="RUN" pad="30 P$30"/>
<connect gate="U$1" pin="SWCLK" pad="41 P$41"/>
<connect gate="U$1" pin="SWDIO" pad="43 P$43"/>
<connect gate="U$1" pin="SWGND" pad="42 P$42"/>
<connect gate="U$1" pin="VBUS" pad="40 P$40"/>
<connect gate="U$1" pin="VSYS" pad="39 P$39"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMD" package="PICO-PKG-SMD">
<connects>
<connect gate="U$1" pin="3V3(OUT)" pad="P$36"/>
<connect gate="U$1" pin="3V3_EN" pad="P$37"/>
<connect gate="U$1" pin="ADC_REF" pad="P$35"/>
<connect gate="U$1" pin="GND" pad="P$3 P$8 P$13 P$18 P$23 P$28 P$33 P$38"/>
<connect gate="U$1" pin="GP0" pad="P$1"/>
<connect gate="U$1" pin="GP1" pad="P$2"/>
<connect gate="U$1" pin="GP10" pad="P$14"/>
<connect gate="U$1" pin="GP11" pad="P$15"/>
<connect gate="U$1" pin="GP12" pad="P$16"/>
<connect gate="U$1" pin="GP13" pad="P$17"/>
<connect gate="U$1" pin="GP14" pad="P$19"/>
<connect gate="U$1" pin="GP15" pad="P$20"/>
<connect gate="U$1" pin="GP16" pad="P$21"/>
<connect gate="U$1" pin="GP17" pad="P$22"/>
<connect gate="U$1" pin="GP18" pad="P$24"/>
<connect gate="U$1" pin="GP19" pad="P$25"/>
<connect gate="U$1" pin="GP2" pad="P$4"/>
<connect gate="U$1" pin="GP20" pad="P$26"/>
<connect gate="U$1" pin="GP21" pad="P$27"/>
<connect gate="U$1" pin="GP22" pad="P$29"/>
<connect gate="U$1" pin="GP26" pad="P$31"/>
<connect gate="U$1" pin="GP27" pad="P$32"/>
<connect gate="U$1" pin="GP28" pad="P$34"/>
<connect gate="U$1" pin="GP3" pad="P$5"/>
<connect gate="U$1" pin="GP4" pad="P$6"/>
<connect gate="U$1" pin="GP5" pad="P$7"/>
<connect gate="U$1" pin="GP6" pad="P$9"/>
<connect gate="U$1" pin="GP7" pad="P$10"/>
<connect gate="U$1" pin="GP8" pad="P$11"/>
<connect gate="U$1" pin="GP9" pad="P$12"/>
<connect gate="U$1" pin="RUN" pad="P$30"/>
<connect gate="U$1" pin="SWCLK" pad="P$41"/>
<connect gate="U$1" pin="SWDIO" pad="P$43"/>
<connect gate="U$1" pin="SWGND" pad="P$42"/>
<connect gate="U$1" pin="VBUS" pad="P$40"/>
<connect gate="U$1" pin="VSYS" pad="P$39"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="TH" package="PICO-PKG-TH">
<connects>
<connect gate="U$1" pin="3V3(OUT)" pad="36"/>
<connect gate="U$1" pin="3V3_EN" pad="37"/>
<connect gate="U$1" pin="ADC_REF" pad="35"/>
<connect gate="U$1" pin="GND" pad="3 8 13 18 23 28 33 38"/>
<connect gate="U$1" pin="GP0" pad="1"/>
<connect gate="U$1" pin="GP1" pad="2"/>
<connect gate="U$1" pin="GP10" pad="14"/>
<connect gate="U$1" pin="GP11" pad="15"/>
<connect gate="U$1" pin="GP12" pad="16"/>
<connect gate="U$1" pin="GP13" pad="17"/>
<connect gate="U$1" pin="GP14" pad="19"/>
<connect gate="U$1" pin="GP15" pad="20"/>
<connect gate="U$1" pin="GP16" pad="21"/>
<connect gate="U$1" pin="GP17" pad="22"/>
<connect gate="U$1" pin="GP18" pad="24"/>
<connect gate="U$1" pin="GP19" pad="25"/>
<connect gate="U$1" pin="GP2" pad="4"/>
<connect gate="U$1" pin="GP20" pad="26"/>
<connect gate="U$1" pin="GP21" pad="27"/>
<connect gate="U$1" pin="GP22" pad="29"/>
<connect gate="U$1" pin="GP26" pad="31"/>
<connect gate="U$1" pin="GP27" pad="32"/>
<connect gate="U$1" pin="GP28" pad="34"/>
<connect gate="U$1" pin="GP3" pad="5"/>
<connect gate="U$1" pin="GP4" pad="6"/>
<connect gate="U$1" pin="GP5" pad="7"/>
<connect gate="U$1" pin="GP6" pad="9"/>
<connect gate="U$1" pin="GP7" pad="10"/>
<connect gate="U$1" pin="GP8" pad="11"/>
<connect gate="U$1" pin="GP9" pad="12"/>
<connect gate="U$1" pin="RUN" pad="30"/>
<connect gate="U$1" pin="SWCLK" pad="41"/>
<connect gate="U$1" pin="SWDIO" pad="43"/>
<connect gate="U$1" pin="SWGND" pad="42"/>
<connect gate="U$1" pin="VBUS" pad="40"/>
<connect gate="U$1" pin="VSYS" pad="39"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X01">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" shape="octagon"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
<package name="2X08">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="-1.905" x2="-9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-2.54" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.905" x2="-9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="2.54" x2="-8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="2.54" x2="-7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="2.54" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="2.54" x2="7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="2.54" x2="10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="15" x="8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="16" x="8.89" y="1.27" drill="1.016" shape="octagon"/>
<text x="-10.16" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-9.144" y1="-1.524" x2="-8.636" y2="-1.016" layer="51"/>
<rectangle x1="-9.144" y1="1.016" x2="-8.636" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="1.016" x2="-6.096" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="-1.524" x2="-6.096" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="1.016" x2="-3.556" y2="1.524" layer="51"/>
<rectangle x1="-4.064" y1="-1.524" x2="-3.556" y2="-1.016" layer="51"/>
<rectangle x1="-1.524" y1="1.016" x2="-1.016" y2="1.524" layer="51"/>
<rectangle x1="1.016" y1="1.016" x2="1.524" y2="1.524" layer="51"/>
<rectangle x1="3.556" y1="1.016" x2="4.064" y2="1.524" layer="51"/>
<rectangle x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.016" layer="51"/>
<rectangle x1="1.016" y1="-1.524" x2="1.524" y2="-1.016" layer="51"/>
<rectangle x1="3.556" y1="-1.524" x2="4.064" y2="-1.016" layer="51"/>
<rectangle x1="6.096" y1="1.016" x2="6.604" y2="1.524" layer="51"/>
<rectangle x1="6.096" y1="-1.524" x2="6.604" y2="-1.016" layer="51"/>
<rectangle x1="8.636" y1="1.016" x2="9.144" y2="1.524" layer="51"/>
<rectangle x1="8.636" y1="-1.524" x2="9.144" y2="-1.016" layer="51"/>
</package>
<package name="2X08/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<pad name="2" x="-8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="-3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="12" x="3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="14" x="6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="16" x="8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="-3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="11" x="3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="13" x="6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="15" x="8.89" y="-6.35" drill="1.016" shape="octagon"/>
<text x="-10.795" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="12.065" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-5.461" x2="-8.509" y2="-4.699" layer="21"/>
<rectangle x1="-9.271" y1="-4.699" x2="-8.509" y2="-2.921" layer="51"/>
<rectangle x1="-6.731" y1="-4.699" x2="-5.969" y2="-2.921" layer="51"/>
<rectangle x1="-6.731" y1="-5.461" x2="-5.969" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-5.461" x2="-3.429" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-4.699" x2="-3.429" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-4.699" x2="-0.889" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-5.461" x2="-0.889" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-5.461" x2="1.651" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-4.699" x2="1.651" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-4.699" x2="4.191" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-5.461" x2="4.191" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-5.461" x2="6.731" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-4.699" x2="6.731" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-4.699" x2="9.271" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-5.461" x2="9.271" y2="-4.699" layer="21"/>
</package>
<package name="1X02">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-2.6162" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
</package>
<package name="1X02/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-3.175" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="4.445" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PINHD1">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="2.54" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
<symbol name="PINH2X8">
<wire x1="-6.35" y1="-12.7" x2="8.89" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-12.7" x2="8.89" y2="10.16" width="0.4064" layer="94"/>
<wire x1="8.89" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-12.7" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-15.24" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="11" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="13" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="5.08" y="-7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="15" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="16" x="5.08" y="-10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
<symbol name="PINHD2">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="-6.35" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="5.08" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X1" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X01">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-2X8" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X8" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X08">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="2X08/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X2" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X02">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X02/90">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="esp8266modules">
<packages>
<package name="WEMOS-D1-MINI">
<description>WeMos.cc
D1 mini
ESP8266 module</description>
<wire x1="9.17" y1="15.216" x2="9.17" y2="9.416" width="0.127" layer="21"/>
<wire x1="-6.83" y1="9.416" x2="-6.83" y2="15.216" width="0.127" layer="21"/>
<wire x1="-6.83" y1="15.216" x2="9.17" y2="15.216" width="0.127" layer="21"/>
<wire x1="-6.83" y1="9.416" x2="9.17" y2="9.416" width="0.127" layer="21"/>
<pad name="5V" x="12.7" y="-10.16" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="GND" x="12.7" y="-7.62" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="D4" x="12.7" y="-5.08" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="D3" x="12.7" y="-2.54" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="D2" x="12.7" y="0" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="D1" x="12.7" y="2.54" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="RX" x="12.7" y="5.08" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="TX" x="12.7" y="7.62" drill="1.016" diameter="1.8288" shape="long"/>
<pad name="3V3" x="-10.16" y="-10.16" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="D8" x="-10.16" y="-7.62" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="D7" x="-10.16" y="-5.08" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="D6" x="-10.16" y="-2.54" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="D5" x="-10.16" y="0" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="D0" x="-10.16" y="2.54" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="A0" x="-10.16" y="5.08" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<pad name="RESET" x="-10.16" y="7.62" drill="1.016" diameter="1.8288" shape="long" rot="R180"/>
<text x="-2.54" y="-6.35" size="1.4224" layer="21">WeMos.cc
D1 mini</text>
<text x="12.7" y="-17.78" size="1.4224" layer="25" align="bottom-right">&gt;Name</text>
<wire x1="-6.8326" y1="9.4234" x2="-6.8326" y2="-8.89" width="0.127" layer="21"/>
<wire x1="9.144" y1="9.4234" x2="9.1694" y2="9.4234" width="0.127" layer="21"/>
<wire x1="9.1694" y1="9.4234" x2="9.1694" y2="-8.89" width="0.127" layer="21"/>
<wire x1="13.97" y1="12.7" x2="13.97" y2="-19.05" width="0.127" layer="21"/>
<wire x1="-8.89" y1="15.24" x2="11.43" y2="15.24" width="0.127" layer="21"/>
<wire x1="-11.43" y1="12.7" x2="-8.89" y2="15.24" width="0.127" layer="21" curve="-90"/>
<wire x1="11.43" y1="15.24" x2="13.97" y2="12.7" width="0.127" layer="21" curve="-90"/>
<wire x1="-11.43" y1="12.7" x2="-11.43" y2="-19.05" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-19.05" x2="13.97" y2="-19.05" width="0.127" layer="21"/>
<wire x1="-6.8326" y1="-8.89" x2="9.144" y2="-8.89" width="0.127" layer="21"/>
<text x="-8.89" y="7.62" size="0.762" layer="25" align="center-left">RST</text>
<text x="-8.89" y="5.08" size="0.762" layer="25" align="center-left">A0</text>
<text x="-8.89" y="2.54" size="0.762" layer="25" align="center-left">D0</text>
<text x="-8.89" y="0" size="0.762" layer="25" align="center-left">D5</text>
<text x="-8.89" y="-2.54" size="0.762" layer="25" align="center-left">D6</text>
<text x="-8.89" y="-5.08" size="0.762" layer="25" align="center-left">D7</text>
<text x="-8.89" y="-7.62" size="0.762" layer="25" align="center-left">D8</text>
<text x="-8.89" y="-10.16" size="0.762" layer="25" align="center-left">3V3</text>
<text x="11.43" y="-10.16" size="0.762" layer="25" rot="R180" align="center-left">5V</text>
<text x="11.43" y="-7.62" size="0.762" layer="25" rot="R180" align="center-left">GND</text>
<text x="11.43" y="-5.08" size="0.762" layer="25" rot="R180" align="center-left">D4</text>
<text x="11.43" y="-2.54" size="0.762" layer="25" rot="R180" align="center-left">D3</text>
<text x="11.43" y="0" size="0.762" layer="25" rot="R180" align="center-left">D2</text>
<text x="11.43" y="2.54" size="0.762" layer="25" rot="R180" align="center-left">D1</text>
<text x="11.43" y="5.08" size="0.762" layer="25" rot="R180" align="center-left">RX</text>
<text x="11.43" y="7.62" size="0.762" layer="25" rot="R180" align="center-left">TX</text>
<wire x1="-2.54" y1="-19.05" x2="5.08" y2="-19.05" width="0.2032" layer="21"/>
<wire x1="5.08" y1="-19.05" x2="5.08" y2="-13.97" width="0.2032" layer="21"/>
<wire x1="5.08" y1="-13.97" x2="-2.54" y2="-13.97" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="-13.97" x2="-2.54" y2="-19.05" width="0.2032" layer="21"/>
<text x="1.27" y="12.7" size="1.4224" layer="25" align="center">ANTENNA
KEEP CLEAR</text>
<text x="1.27" y="-16.51" size="1.016" layer="25" align="center">USB
MICRO</text>
<wire x1="-6.35" y1="-12.7" x2="-10.16" y2="-12.7" width="0.2032" layer="21"/>
<wire x1="-10.16" y1="-12.7" x2="-10.16" y2="-17.78" width="0.2032" layer="21"/>
<wire x1="-10.16" y1="-17.78" x2="-6.35" y2="-17.78" width="0.2032" layer="21"/>
<wire x1="-6.35" y1="-17.78" x2="-6.35" y2="-12.7" width="0.2032" layer="21"/>
<text x="-8.255" y="-15.24" size="0.635" layer="25" align="center">RESET
SWITCH</text>
</package>
</packages>
<symbols>
<symbol name="WEMOS-D1-MINI">
<description>WeMos.cc
D1 mini
ESP8266 module</description>
<wire x1="-10.16" y1="12.7" x2="-10.16" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-12.7" x2="12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="-10.16" y2="12.7" width="0.254" layer="94"/>
<pin name="RESET" x="-15.24" y="10.16" visible="pin" length="middle"/>
<pin name="A0" x="-15.24" y="7.62" visible="pin" length="middle"/>
<pin name="D0" x="-15.24" y="5.08" visible="pin" length="middle"/>
<pin name="D5" x="-15.24" y="2.54" visible="pin" length="middle"/>
<pin name="D6" x="-15.24" y="0" visible="pin" length="middle"/>
<pin name="D7" x="-15.24" y="-2.54" visible="pin" length="middle"/>
<pin name="D8" x="-15.24" y="-5.08" visible="pin" length="middle"/>
<pin name="3V3" x="-15.24" y="-7.62" visible="pin" length="middle"/>
<pin name="5V" x="17.78" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="GND" x="17.78" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D4" x="17.78" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D3" x="17.78" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="D2" x="17.78" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D1" x="17.78" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="RX" x="17.78" y="7.62" visible="pin" length="middle" rot="R180"/>
<pin name="TX" x="17.78" y="10.16" visible="pin" length="middle" rot="R180"/>
<text x="-10.16" y="12.7" size="1.778" layer="95">&gt;Name</text>
<text x="-7.62" y="-15.24" size="1.778" layer="96">&gt;Value</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="WEMOS-D1-MINI" prefix="WEMOS" uservalue="yes">
<description>WeMos.cc
D1 mini
ESP8266 module</description>
<gates>
<gate name="D1" symbol="WEMOS-D1-MINI" x="0" y="0"/>
</gates>
<devices>
<device name="" package="WEMOS-D1-MINI">
<connects>
<connect gate="D1" pin="3V3" pad="3V3"/>
<connect gate="D1" pin="5V" pad="5V"/>
<connect gate="D1" pin="A0" pad="A0"/>
<connect gate="D1" pin="D0" pad="D0"/>
<connect gate="D1" pin="D1" pad="D1"/>
<connect gate="D1" pin="D2" pad="D2"/>
<connect gate="D1" pin="D3" pad="D3"/>
<connect gate="D1" pin="D4" pad="D4"/>
<connect gate="D1" pin="D5" pad="D5"/>
<connect gate="D1" pin="D6" pad="D6"/>
<connect gate="D1" pin="D7" pad="D7"/>
<connect gate="D1" pin="D8" pad="D8"/>
<connect gate="D1" pin="GND" pad="GND"/>
<connect gate="D1" pin="RESET" pad="RESET"/>
<connect gate="D1" pin="RX" pad="RX"/>
<connect gate="D1" pin="TX" pad="TX"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="RpiPico" deviceset="RASPBERRY_PICO" device="TH"/>
<part name="JP2" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP3" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP4" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="WEMOS1" library="esp8266modules" deviceset="WEMOS-D1-MINI" device=""/>
<part name="JP6" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP7" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP8" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP5" library="pinhead" deviceset="PINHD-2X8" device=""/>
<part name="JP1" library="pinhead" deviceset="PINHD-1X2" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U1" gate="U$1" x="27.94" y="0"/>
<instance part="JP2" gate="G$1" x="58.42" y="33.02"/>
<instance part="JP3" gate="G$1" x="58.42" y="-35.56"/>
<instance part="JP4" gate="G$1" x="0" y="43.18" rot="R90"/>
<instance part="WEMOS1" gate="D1" x="-91.44" y="-2.54"/>
<instance part="JP6" gate="G$1" x="-53.34" y="-15.24"/>
<instance part="JP7" gate="G$1" x="-53.34" y="-5.08"/>
<instance part="JP8" gate="G$1" x="-114.3" y="-10.16" rot="R180"/>
<instance part="JP5" gate="A" x="-15.24" y="0"/>
<instance part="JP1" gate="G$1" x="-40.64" y="-15.24" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$4" class="0">
<segment>
<pinref part="WEMOS1" gate="D1" pin="3V3"/>
<pinref part="JP8" gate="G$1" pin="1"/>
<wire x1="-106.68" y1="-10.16" x2="-111.76" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U1" gate="U$1" pin="VSYS"/>
<pinref part="JP2" gate="G$1" pin="1"/>
<wire x1="45.72" y1="33.02" x2="55.88" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U1" gate="U$1" pin="GP1"/>
<wire x1="0" y1="22.86" x2="10.16" y2="22.86" width="0.1524" layer="91"/>
<pinref part="WEMOS1" gate="D1" pin="TX"/>
<wire x1="-66.04" y1="7.62" x2="-73.66" y2="7.62" width="0.1524" layer="91"/>
<wire x1="-66.04" y1="7.62" x2="-66.04" y2="25.4" width="0.1524" layer="91"/>
<wire x1="-66.04" y1="25.4" x2="0" y2="25.4" width="0.1524" layer="91"/>
<pinref part="JP4" gate="G$1" pin="1"/>
<wire x1="0" y1="25.4" x2="0" y2="40.64" width="0.1524" layer="91"/>
<wire x1="0" y1="22.86" x2="0" y2="25.4" width="0.1524" layer="91"/>
<junction x="0" y="25.4"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="JP7" gate="G$1" pin="1"/>
<wire x1="-55.88" y1="-5.08" x2="-68.58" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="WEMOS1" gate="D1" pin="GND"/>
<wire x1="-68.58" y1="-5.08" x2="-73.66" y2="-7.62" width="0.1524" layer="91"/>
<pinref part="JP1" gate="G$1" pin="2"/>
<wire x1="-40.64" y1="-17.78" x2="-40.64" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="-5.08" x2="-55.88" y2="-5.08" width="0.1524" layer="91"/>
<junction x="-55.88" y="-5.08"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="WEMOS1" gate="D1" pin="5V"/>
<wire x1="-73.66" y1="-10.16" x2="-68.58" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="-10.16" x2="-63.5" y2="-15.24" width="0.1524" layer="91"/>
<pinref part="JP6" gate="G$1" pin="1"/>
<wire x1="-63.5" y1="-15.24" x2="-55.88" y2="-15.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="JP5" gate="A" pin="1"/>
<wire x1="-17.78" y1="7.62" x2="-25.4" y2="7.62" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="7.62" x2="-25.4" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="12.7" x2="0" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP3"/>
<wire x1="0" y1="12.7" x2="10.16" y2="15.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="JP5" gate="A" pin="3"/>
<wire x1="-17.78" y1="5.08" x2="-27.94" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="5.08" x2="-27.94" y2="15.24" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="15.24" x2="0" y2="15.24" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP2"/>
<wire x1="0" y1="15.24" x2="10.16" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="JP5" gate="A" pin="13"/>
<wire x1="-17.78" y1="-7.62" x2="-27.94" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="-7.62" x2="-27.94" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="-17.78" x2="-2.54" y2="-17.78" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP10"/>
<wire x1="-2.54" y1="-17.78" x2="10.16" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="JP5" gate="A" pin="11"/>
<wire x1="-17.78" y1="-5.08" x2="-30.48" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="-5.08" x2="-30.48" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="-20.32" x2="-2.54" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP11"/>
<wire x1="-2.54" y1="-20.32" x2="10.16" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="JP5" gate="A" pin="9"/>
<wire x1="-17.78" y1="-2.54" x2="-33.02" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="-2.54" x2="-33.02" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="-22.86" x2="-2.54" y2="-22.86" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP12"/>
<wire x1="-2.54" y1="-22.86" x2="10.16" y2="-12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="JP5" gate="A" pin="2"/>
<wire x1="-10.16" y1="7.62" x2="0" y2="7.62" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP4"/>
<wire x1="0" y1="7.62" x2="10.16" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="JP5" gate="A" pin="4"/>
<wire x1="-10.16" y1="5.08" x2="0" y2="5.08" width="0.1524" layer="91"/>
<pinref part="U1" gate="U$1" pin="GP5"/>
<wire x1="0" y1="5.08" x2="10.16" y2="10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U1" gate="U$1" pin="RUN"/>
<wire x1="45.72" y1="22.86" x2="68.58" y2="22.86" width="0.1524" layer="91"/>
<wire x1="68.58" y1="22.86" x2="68.58" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="68.58" y1="-43.18" x2="-43.18" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-43.18" x2="-121.92" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="-43.18" x2="-121.92" y2="2.54" width="0.1524" layer="91"/>
<pinref part="WEMOS1" gate="D1" pin="D0"/>
<wire x1="-106.68" y1="2.54" x2="-121.92" y2="2.54" width="0.1524" layer="91"/>
<pinref part="JP1" gate="G$1" pin="1"/>
<wire x1="-43.18" y1="-17.78" x2="-43.18" y2="-43.18" width="0.1524" layer="91"/>
<junction x="-43.18" y="-43.18"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="JP5" gate="A" pin="16"/>
<wire x1="-10.16" y1="-10.16" x2="-5.08" y2="-10.16" width="0.1524" layer="91"/>
<label x="2.54" y="-10.16" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="14"/>
<wire x1="-10.16" y1="-7.62" x2="-5.08" y2="-7.62" width="0.1524" layer="91"/>
<label x="2.54" y="-7.62" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="15"/>
<wire x1="-17.78" y1="-10.16" x2="-22.86" y2="-10.16" width="0.1524" layer="91"/>
<label x="-22.86" y="-12.7" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="12"/>
<wire x1="-10.16" y1="-5.08" x2="-7.62" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="-5.08" x2="-7.62" y2="-5.08" width="0.1524" layer="91"/>
<label x="2.54" y="-5.08" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="10"/>
<wire x1="-10.16" y1="-2.54" x2="-5.08" y2="-2.54" width="0.1524" layer="91"/>
<label x="2.54" y="-2.54" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="U$1" pin="GND"/>
<pinref part="JP3" gate="G$1" pin="1"/>
<wire x1="45.72" y1="-35.56" x2="55.88" y2="-35.56" width="0.1524" layer="91"/>
<label x="55.88" y="-27.94" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="N$54" class="0">
<segment>
<pinref part="JP5" gate="A" pin="8"/>
<wire x1="-10.16" y1="0" x2="-5.08" y2="0" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$55" class="0">
<segment>
<pinref part="JP5" gate="A" pin="6"/>
<wire x1="-10.16" y1="2.54" x2="-7.62" y2="2.54" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="2.54" x2="-7.62" y2="2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$50" class="0">
<segment>
<pinref part="JP5" gate="A" pin="5"/>
<wire x1="-17.78" y1="2.54" x2="-22.86" y2="2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$57" class="0">
<segment>
<pinref part="JP5" gate="A" pin="7"/>
<wire x1="-17.78" y1="0" x2="-22.86" y2="0" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
</compatibility>
</eagle>
