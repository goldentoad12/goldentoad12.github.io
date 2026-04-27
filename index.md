---
layout: single

header:
  image: /assets/images/header.jpg
  show_overlay_excerpt: true
  excerpt: "My goal is to turn environmental data into actionable insight for climate resilience and sustainable systems."

feature_row:
  - image_path: /assets/images/arduino.jpg
    alt: "Arduino Projects"
    title: "Arduino Projects"
    url: "{{ '/projectsarduino/' | relative_url }}"
    btn_label: "Explore"
    btn_class: "btn--primary"
    excerpt: "This is some sample content that goes here with **Markdown** formatting."

  - image_path: /assets/images/gis.jpg
    alt: "GIS & Spatial Analysis"
    title: "GIS & Spatial Analysis"
    url: "{{ '/projectsgis/' | relative_url }}"
    btn_label: "Explore"
    btn_class: "btn--primary"
    excerpt: "This is some sample content that goes here with **Markdown** formatting."

  - image_path: /assets/images/publication.jpg
    alt: "Research & Publications"
    title: "Research & Publications"
    url: "{{ '/publications/' | relative_url }}"
    btn_label: "Explore"
    btn_class: "btn--primary"
    excerpt: "This is some sample content that goes here with **Markdown** formatting."
    
sidebar:
  nav: "docs"
---

Welcome! This site will contain the following, an about me, my GIS and Arduino projects, my current academic publications, and an up to date resume. Use the navigation bar at the top of the screen to view everything. 

{% include feature_row %}


