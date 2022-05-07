$(document).ready(function() {
  $(".browse").click();
})

gsap.set(".item-name", {y: 6})

$(".item").click(function() {
  $(".item").removeClass("active")
  $(".item").mouseleave();
  $(this).mouseenter();
  $(this).addClass("active")
  
  const itemImg = $(this).find(".item-img")
  const tl = gsap.timeline();
    tl.to(itemImg, .3, {scale: 1.2})
    tl.to(itemImg, .3, {delay: -.15, scale: 1, ease: Back.easeOut})
  
  const itemImgFill = $(this).find(".itemFill")
  gsap.to(".itemFill", .3, {fill: "#B9C2CD"})
  gsap.to(itemImgFill, .3, {fill: "#ea4c89"})
  
  const itemImgStroke = $(this).find(".itemStroke")
  gsap.to(".itemStroke", .3, {stroke: "#B9C2CD"})
  gsap.to(itemImgStroke, .3, {stroke: "#ea4c89"})
})

$(".item").hover(function() {
  const itemName = $(this).find(".item-name")
  gsap.to(itemName, .3, {opacity: 1, y: 0, ease: Power1.easeOut})
})

$(".item").mouseleave(function() {
  if ($(this).hasClass("active")) {
  } else {
    const itemName = $(this).find(".item-name")
    gsap.to(itemName, .3, {opacity: 0, y: 6, ease: Power1.easeOut})
  }
})

const itemBrowse = document.querySelector(".browse")
const itemBrowseX = itemBrowse.offsetLeft
const itemProfile = document.querySelector(".profile")
const itemProfileX = itemProfile.offsetLeft
const itemChat = document.querySelector(".chat")
const itemChatX = itemChat.offsetLeft
const itemMenu = document.querySelector(".menu")
const itemMenuX = itemMenu.offsetLeft

const upperBar = document.querySelector(".upper-bar")
const upperBarX = upperBar.offsetLeft

const tl = gsap.timeline();
  tl.to(upperBar, .3, {scaleX: 1.5, ease: Back.easeOut})
  tl.to(upperBar, .3, {scaleX: 1, ease: Back.easeOut})
  tl.pause()

$(itemBrowse).click(function() {
  gsap.to(upperBar, .6, {x: itemBrowseX - 23, ease: Back.easeOut})
  tl.play()
  
  gsap.to(".items", .6, {rotate: -3, ease: Back.easeOut})
  gsap.to(".items", .6, {delay: .15, rotate: 0, ease: Back.easeOut})
  
  setTimeout(function() {
    tl.pause()
    tl.progress(0)
  }, 600)
})

$(itemProfile).click(function() {
  gsap.to(upperBar, .6, {x: itemProfileX - 23, ease: Back.easeOut})
  tl.play()
  
  gsap.to(".items", .6, {rotate: -1, ease: Back.easeOut})
  gsap.to(".items", .6, {delay: .15, rotate: 0, ease: Back.easeOut})
  
  setTimeout(function() {
    tl.pause()
    tl.progress(0)
  }, 600)
})

$(itemChat).click(function() {
  gsap.to(upperBar, .6, {x: itemChatX - 23, ease: Back.easeOut})
  tl.play()
  
  gsap.to(".items", .6, {rotate: 1, ease: Back.easeOut})
  gsap.to(".items", .6, {delay: .15, rotate: 0, ease: Back.easeOut})
  
  setTimeout(function() {
    tl.pause()
    tl.progress(0)
  }, 600)
})

$(itemMenu).click(function() {
  gsap.to(upperBar, .6, {x: itemMenuX - 23, ease: Back.easeOut})
  tl.play()
  
  gsap.to(".items", .6, {rotate: 3, ease: Back.easeOut})
  gsap.to(".items", .6, {delay: .15, rotate: 0, ease: Back.easeOut})
  
  setTimeout(function() {
    tl.pause()
    tl.progress(0)
  }, 600)
})